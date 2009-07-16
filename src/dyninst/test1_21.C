/*
 * Copyright (c) 1996-2004 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * This license is for research uses.  For such uses, there is no
 * charge. We define "research use" to mean you may freely use it
 * inside your organization for whatever purposes you see fit. But you
 * may not re-distribute Paradyn or parts of Paradyn, in any form
 * source or binary (including derivatives), electronic or otherwise,
 * to any other organization or entity without our permission.
 * 
 * (for other uses, please contact us at paradyn@cs.wisc.edu)
 * 
 * All warranties, including without limitation, any warranty of
 * merchantability or fitness for a particular purpose, are hereby
 * excluded.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * Even if advised of the possibility of such damages, under no
 * circumstances shall we (or any other person or entity with
 * proprietary rights in the software licensed hereunder) be liable
 * to you or any third party for direct, indirect, or consequential
 * damages of any character regardless of type of action, including,
 * without limitation, loss of profits, loss of use, loss of good
 * will, or computer failure or malfunction.  You agree to indemnify
 * us (and any other person or entity with proprietary rights in the
 * software licensed hereunder) for any and all liability it may
 * incur to third parties resulting from your use of Paradyn.
 */

// $Id: test1_21.C,v 1.1 2008/10/30 19:18:23 legendre Exp $
/*
 * #Name: test1_21
 * #Desc: findFunction in module
 * #Dep: 
 * #Arch: sparc_sun_solaris2_4_test,alpha_dec_osf4_0_test,i386_unknown_solaris2_5_test,i386_unknown_linux2_0_test,ia64_unknown_linux2_4_test,mips_sgi_irix6_4_test,rs6000_ibm_aix4_1_test,x86_64_unknown_linux2_4_test
 * #Notes: This test uses some special magic for libNameA and libNameB that should probably be altered
 */

#include "BPatch.h"
#include "BPatch_Vector.h"
#include "BPatch_thread.h"
#include "BPatch_snippet.h"

#include "test_lib.h"

#ifdef os_windows_test
#define snprintf _snprintf
#endif

#include "dyninst_comp.h"

class test1_21_Mutator : public DyninstMutator {
	const char *libNameAroot;
	const char *libNameBroot;
	char libNameA[128], libNameB[128];

	public:
	test1_21_Mutator();
	virtual test_results_t executeTest();
	test_results_t mutatorTest21();
};

test1_21_Mutator::test1_21_Mutator() : libNameAroot("libtestA"),
									   libNameBroot("libtestB") 
{}

extern "C" DLLEXPORT  TestMutator *test1_21_factory() 
{
	return new test1_21_Mutator();
}

//
// Start Test Case #21 - mutator side (findFunction in module)
//
// There is no corresponding failure (test2) testing because the only
// bad input to replaceFunction is a non-existent BPatch_function.
// But this is already checked by the "non-existent function" test in
// test2.

test_results_t test1_21_Mutator::mutatorTest21() 
{
#if defined(os_aix_test) \
	|| defined(os_osf_test) \
	|| defined(os_solaris_test) \
	|| defined(os_linux_test) \
	|| defined(os_windows_test)

	// Lookup the libtestA.so and libtestB.so modules that we've just loaded

	BPatch_module *modA = NULL;
	BPatch_module *modB = NULL;
	BPatch_Vector<BPatch_module *> *mods = appImage->getModules();

	if (!mods || mods->size() == 0) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  Mutator couldn't search modules of mutatee\n");
		return FAILED;
	}

	for (unsigned int i = 0; i < mods->size() && !(modA && modB); i++) 
	{
		char buf[1024];
		BPatch_module *m = (*mods)[i];
		m->getName(buf, 1024);

		// module names sometimes have "_module" appended
		if (!strcmpcase(libNameA, buf))
			modA = m;
		else if (!strcmpcase(libNameB, buf))
			modB = m;
	}

	if (! modA || ! modB ) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  Mutator couldn't find shlib in mutatee\n");
		flushErrorLog();
		return FAILED;
	}

	// Find the function CALL21_1 in each of the modules
	BPatch_Vector<BPatch_function *> bpmv;

	if (NULL == modA->findFunction("call21_1", bpmv, false, false, true) || !bpmv.size()) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  %s[%d]: Mutator couldn't find a function in %s\n", 
				__FILE__, __LINE__, libNameA);
		return FAILED;
	}

	BPatch_function *funcA = bpmv[0];
	bpmv.clear();

	if (NULL == modB->findFunction("call21_1", bpmv, false, false, true) || !bpmv.size()) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  %s[%d]: Mutator couldn't find a function in %s\n", 
				__FILE__, __LINE__, libNameB);
		return FAILED;
	} 

	BPatch_function *funcB = bpmv[0];

	// Kludgily test whether the functions are distinct
	if (funcA->getBaseAddr() == funcB->getBaseAddr()) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  Mutator cannot distinguish two functions from different shlibs\n");
		return FAILED;
	}

	//  Now test regex search
	//  Not meant to be an extensive check of all regex usage, just that
	//  the basic mechanism that deals with regexes is not broken

	bpmv.clear();
#if !defined(os_windows_test)
	//   regex "^cb" should match all functions that begin with "cb"
	//   We dont use existing "call" functions here since (at least on
	//   linux, we also find call_gmon_start().  Thus the dummy fns.
	if (NULL == modB->findFunction("^cb", bpmv, false, false, true) || (bpmv.size() != 2)) 
	{

		logerror("**Failed test #21 (findFunction in module, regex)\n");
		logerror("  Expected 2 functions matching ^cb, got %d\n",
				bpmv.size());
		char buf[128];
		for (unsigned int i = 0; i < bpmv.size(); ++i) 
			logerror("  matched function: %s\n", 
					bpmv[i]->getName(buf, 128));
		return FAILED;
	}

	bpmv.clear();

	if (NULL == modB->findFunction("^cbll21", bpmv, false, false, true) || (bpmv.size() != 1)) 
	{
		logerror("**Failed test #21 (findFunction in module, regex)\n");
		logerror("  Expected 1 function matching ^cbll21, got %d\n",
				bpmv.size());
		return FAILED;
	}
#endif
	return PASSED;    
#else // Not running on one of the specified platforms
	return SKIPPED;
#endif
}



// Wrapper to call readyTest
test_results_t test1_21_Mutator::executeTest() 
{
	int pointer_size = 0;
#if defined(arch_x86_64_test) || defined (ppc64_linux_test)

	pointer_size = pointerSize(appImage);
#endif
	strncpy(libNameA, libNameAroot, 127);
	addLibArchExt(libNameA,127, pointer_size);
	strncpy(libNameB, libNameBroot, 127);
	addLibArchExt(libNameB,127, pointer_size);

	char libA[128], libB[128];
	snprintf(libA, 128, "./%s", libNameA);
	snprintf(libB, 128, "./%s", libNameB);

	if (! appAddrSpace->loadLibrary(libA)) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  Mutator couldn't load %s into mutatee\n", libNameA);
		return FAILED;
	}

	if (! appAddrSpace->loadLibrary(libB)) 
	{
		logerror("**Failed test #21 (findFunction in module)\n");
		logerror("  Mutator couldn't load %s into mutatee\n", libNameB);
		return FAILED;
	}

	return mutatorTest21();
}