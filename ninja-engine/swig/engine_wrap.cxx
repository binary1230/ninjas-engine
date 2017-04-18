/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.9
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */


#ifndef SWIGCSHARP
#define SWIGCSHARP
#endif



#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Support for throwing C# exceptions from C/C++. There are two types: 
 * Exceptions that take a message and ArgumentExceptions that take a message and a parameter name. */
typedef enum {
  SWIG_CSharpApplicationException,
  SWIG_CSharpArithmeticException,
  SWIG_CSharpDivideByZeroException,
  SWIG_CSharpIndexOutOfRangeException,
  SWIG_CSharpInvalidCastException,
  SWIG_CSharpInvalidOperationException,
  SWIG_CSharpIOException,
  SWIG_CSharpNullReferenceException,
  SWIG_CSharpOutOfMemoryException,
  SWIG_CSharpOverflowException,
  SWIG_CSharpSystemException
} SWIG_CSharpExceptionCodes;

typedef enum {
  SWIG_CSharpArgumentException,
  SWIG_CSharpArgumentNullException,
  SWIG_CSharpArgumentOutOfRangeException
} SWIG_CSharpExceptionArgumentCodes;

typedef void (SWIGSTDCALL* SWIG_CSharpExceptionCallback_t)(const char *);
typedef void (SWIGSTDCALL* SWIG_CSharpExceptionArgumentCallback_t)(const char *, const char *);

typedef struct {
  SWIG_CSharpExceptionCodes code;
  SWIG_CSharpExceptionCallback_t callback;
} SWIG_CSharpException_t;

typedef struct {
  SWIG_CSharpExceptionArgumentCodes code;
  SWIG_CSharpExceptionArgumentCallback_t callback;
} SWIG_CSharpExceptionArgument_t;

static SWIG_CSharpException_t SWIG_csharp_exceptions[] = {
  { SWIG_CSharpApplicationException, NULL },
  { SWIG_CSharpArithmeticException, NULL },
  { SWIG_CSharpDivideByZeroException, NULL },
  { SWIG_CSharpIndexOutOfRangeException, NULL },
  { SWIG_CSharpInvalidCastException, NULL },
  { SWIG_CSharpInvalidOperationException, NULL },
  { SWIG_CSharpIOException, NULL },
  { SWIG_CSharpNullReferenceException, NULL },
  { SWIG_CSharpOutOfMemoryException, NULL },
  { SWIG_CSharpOverflowException, NULL },
  { SWIG_CSharpSystemException, NULL }
};

static SWIG_CSharpExceptionArgument_t SWIG_csharp_exceptions_argument[] = {
  { SWIG_CSharpArgumentException, NULL },
  { SWIG_CSharpArgumentNullException, NULL },
  { SWIG_CSharpArgumentOutOfRangeException, NULL }
};

static void SWIGUNUSED SWIG_CSharpSetPendingException(SWIG_CSharpExceptionCodes code, const char *msg) {
  SWIG_CSharpExceptionCallback_t callback = SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions)/sizeof(SWIG_CSharpException_t)) {
    callback = SWIG_csharp_exceptions[code].callback;
  }
  callback(msg);
}

static void SWIGUNUSED SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpExceptionArgumentCodes code, const char *msg, const char *param_name) {
  SWIG_CSharpExceptionArgumentCallback_t callback = SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions_argument)/sizeof(SWIG_CSharpExceptionArgument_t)) {
    callback = SWIG_csharp_exceptions_argument[code].callback;
  }
  callback(msg, param_name);
}


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionCallbacks_engine(
                                                SWIG_CSharpExceptionCallback_t applicationCallback,
                                                SWIG_CSharpExceptionCallback_t arithmeticCallback,
                                                SWIG_CSharpExceptionCallback_t divideByZeroCallback, 
                                                SWIG_CSharpExceptionCallback_t indexOutOfRangeCallback, 
                                                SWIG_CSharpExceptionCallback_t invalidCastCallback,
                                                SWIG_CSharpExceptionCallback_t invalidOperationCallback,
                                                SWIG_CSharpExceptionCallback_t ioCallback,
                                                SWIG_CSharpExceptionCallback_t nullReferenceCallback,
                                                SWIG_CSharpExceptionCallback_t outOfMemoryCallback, 
                                                SWIG_CSharpExceptionCallback_t overflowCallback, 
                                                SWIG_CSharpExceptionCallback_t systemCallback) {
  SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback = applicationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpArithmeticException].callback = arithmeticCallback;
  SWIG_csharp_exceptions[SWIG_CSharpDivideByZeroException].callback = divideByZeroCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIndexOutOfRangeException].callback = indexOutOfRangeCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidCastException].callback = invalidCastCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidOperationException].callback = invalidOperationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIOException].callback = ioCallback;
  SWIG_csharp_exceptions[SWIG_CSharpNullReferenceException].callback = nullReferenceCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOutOfMemoryException].callback = outOfMemoryCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOverflowException].callback = overflowCallback;
  SWIG_csharp_exceptions[SWIG_CSharpSystemException].callback = systemCallback;
}

#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionArgumentCallbacks_engine(
                                                SWIG_CSharpExceptionArgumentCallback_t argumentCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentNullCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentOutOfRangeCallback) {
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback = argumentCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentNullException].callback = argumentNullCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentOutOfRangeException].callback = argumentOutOfRangeCallback;
}


/* Callback for returning strings to C# without leaking memory */
typedef char * (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char *);
static SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback = NULL;


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterStringCallback_engine(SWIG_CSharpStringHelperCallback callback) {
  SWIG_csharp_string_callback = callback;
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, msg, ""); return nullreturn; } else


#include "../stdafx.h"
#include "../gameMode.h"
#include "../gameWorld.h"
#include "../gameState.h"


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_useExitInfo_set(void * jarg1, unsigned int jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool arg2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  arg2 = jarg2 ? true : false; 
  if (arg1) (arg1)->useExitInfo = arg2;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameModeExitInfo_useExitInfo_get(void * jarg1) {
  unsigned int jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result = (bool) ((arg1)->useExitInfo);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_lastModeName_set(void * jarg1, void * jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string arg2 ;
  std::string *argp2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  argp2 = (std::string *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null std::string", 0);
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->lastModeName = arg2;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameModeExitInfo_lastModeName_get(void * jarg1) {
  void * jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result =  ((arg1)->lastModeName);
  jresult = new std::string((const std::string &)result); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_nextModeToLoad_set(void * jarg1, void * jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string arg2 ;
  std::string *argp2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  argp2 = (std::string *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null std::string", 0);
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->nextModeToLoad = arg2;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameModeExitInfo_nextModeToLoad_get(void * jarg1) {
  void * jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result =  ((arg1)->nextModeToLoad);
  jresult = new std::string((const std::string &)result); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_lastPortalName_set(void * jarg1, void * jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string arg2 ;
  std::string *argp2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  argp2 = (std::string *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null std::string", 0);
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->lastPortalName = arg2;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameModeExitInfo_lastPortalName_get(void * jarg1) {
  void * jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  std::string result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result =  ((arg1)->lastPortalName);
  jresult = new std::string((const std::string &)result); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_useNextModeToLoad_set(void * jarg1, unsigned int jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool arg2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  arg2 = jarg2 ? true : false; 
  if (arg1) (arg1)->useNextModeToLoad = arg2;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameModeExitInfo_useNextModeToLoad_get(void * jarg1) {
  unsigned int jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result = (bool) ((arg1)->useNextModeToLoad);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_useLastPortalName_set(void * jarg1, unsigned int jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool arg2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  arg2 = jarg2 ? true : false; 
  if (arg1) (arg1)->useLastPortalName = arg2;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameModeExitInfo_useLastPortalName_get(void * jarg1) {
  unsigned int jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result = (bool) ((arg1)->useLastPortalName);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameModeExitInfo_showInitialText_set(void * jarg1, unsigned int jarg2) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool arg2 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  arg2 = jarg2 ? true : false; 
  if (arg1) (arg1)->showInitialText = arg2;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameModeExitInfo_showInitialText_get(void * jarg1) {
  unsigned int jresult ;
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  bool result;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  result = (bool) ((arg1)->showInitialText);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_GameModeExitInfo() {
  void * jresult ;
  GameModeExitInfo *result = 0 ;
  
  result = (GameModeExitInfo *)new GameModeExitInfo();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_GameModeExitInfo(void * jarg1) {
  GameModeExitInfo *arg1 = (GameModeExitInfo *) 0 ;
  
  arg1 = (GameModeExitInfo *)jarg1; 
  delete arg1;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameMode_Init(void * jarg1, void * jarg2) {
  int jresult ;
  GameMode *arg1 = (GameMode *) 0 ;
  XMLNode arg2 ;
  XMLNode *argp2 ;
  int result;
  
  arg1 = (GameMode *)jarg1; 
  argp2 = (XMLNode *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null XMLNode", 0);
    return 0;
  }
  arg2 = *argp2; 
  result = (int)(arg1)->Init(arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameMode_Shutdown(void * jarg1) {
  GameMode *arg1 = (GameMode *) 0 ;
  
  arg1 = (GameMode *)jarg1; 
  (arg1)->Shutdown();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameMode_Draw(void * jarg1) {
  GameMode *arg1 = (GameMode *) 0 ;
  
  arg1 = (GameMode *)jarg1; 
  (arg1)->Draw();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameMode_Update(void * jarg1) {
  GameMode *arg1 = (GameMode *) 0 ;
  
  arg1 = (GameMode *)jarg1; 
  (arg1)->Update();
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameMode_GetAiFitnessScore(void * jarg1) {
  int jresult ;
  GameMode *arg1 = (GameMode *) 0 ;
  int result;
  
  arg1 = (GameMode *)jarg1; 
  result = (int)(arg1)->GetAiFitnessScore();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameMode_SetExitInfo(void * jarg1, void * jarg2) {
  GameMode *arg1 = (GameMode *) 0 ;
  GameModeExitInfo *arg2 = 0 ;
  
  arg1 = (GameMode *)jarg1; 
  arg2 = (GameModeExitInfo *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "GameModeExitInfo const & type is null", 0);
    return ;
  } 
  (arg1)->SetExitInfo((GameModeExitInfo const &)*arg2);
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameMode_GetExitInfo(void * jarg1) {
  void * jresult ;
  GameMode *arg1 = (GameMode *) 0 ;
  GameModeExitInfo *result = 0 ;
  
  arg1 = (GameMode *)jarg1; 
  result = (GameModeExitInfo *) &(arg1)->GetExitInfo();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameMode_SetOldExitInfo(void * jarg1, void * jarg2) {
  GameMode *arg1 = (GameMode *) 0 ;
  GameModeExitInfo *arg2 = 0 ;
  
  arg1 = (GameMode *)jarg1; 
  arg2 = (GameModeExitInfo *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "GameModeExitInfo const & type is null", 0);
    return ;
  } 
  (arg1)->SetOldExitInfo((GameModeExitInfo const &)*arg2);
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameMode_GetOldExitInfo(void * jarg1) {
  void * jresult ;
  GameMode *arg1 = (GameMode *) 0 ;
  GameModeExitInfo *result = 0 ;
  
  arg1 = (GameMode *)jarg1; 
  result = (GameModeExitInfo *) &(arg1)->GetOldExitInfo();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_GameMode(void * jarg1) {
  GameMode *arg1 = (GameMode *) 0 ;
  
  arg1 = (GameMode *)jarg1; 
  delete arg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameWorld_GetInstance() {
  void * jresult ;
  GameWorld *result = 0 ;
  
  result = (GameWorld *)GameWorld::GetInstance();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SetInstance(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  GameWorld::SetInstance(arg1);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_CreateInstance() {
  GameWorld::CreateInstance();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_FreeInstance() {
  GameWorld::FreeInstance();
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_Init(void * jarg1, void * jarg2) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  XMLNode arg2 ;
  XMLNode *argp2 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  argp2 = (XMLNode *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null XMLNode", 0);
    return 0;
  }
  arg2 = *argp2; 
  result = (int)(arg1)->Init(arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_Shutdown(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->Shutdown();
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameWorld_UseScrollSpeed(void * jarg1) {
  unsigned int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (bool)(arg1)->UseScrollSpeed();
  jresult = result; 
  return jresult;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameWorld_IsLoading(void * jarg1) {
  unsigned int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (bool)(arg1)->IsLoading();
  jresult = result; 
  return jresult;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameWorld_JumpedBackFromADoor(void * jarg1) {
  unsigned int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (bool)((GameWorld const *)arg1)->JumpedBackFromADoor();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SetModalObject(void * jarg1, void * jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  Object *arg2 = (Object *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (Object *)jarg2; 
  (arg1)->SetModalObject(arg2);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_AddObject__SWIG_0(void * jarg1, void * jarg2, unsigned int jarg3) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  Object *arg2 = (Object *) 0 ;
  bool arg3 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (Object *)jarg2; 
  arg3 = jarg3 ? true : false; 
  (arg1)->AddObject(arg2,arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_AddObject__SWIG_1(void * jarg1, void * jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  Object *arg2 = (Object *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (Object *)jarg2; 
  (arg1)->AddObject(arg2);
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameWorld_FindLayer(void * jarg1, char * jarg2) {
  void * jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  char *arg2 = (char *) 0 ;
  ObjectLayer *result = 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (char *)jarg2; 
  result = (ObjectLayer *)(arg1)->FindLayer((char const *)arg2);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameWorld_GetPlayer(void * jarg1, void * jarg2) {
  void * jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  uint arg2 ;
  uint *argp2 ;
  ObjectPlayer *result = 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  argp2 = (uint *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null uint", 0);
    return 0;
  }
  arg2 = *argp2; 
  result = (ObjectPlayer *)(arg1)->GetPlayer(arg2);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameWorld_GetNumPlayers(void * jarg1) {
  void * jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  uint result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (arg1)->GetNumPlayers();
  jresult = new uint((const uint &)result); 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_Draw(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->Draw();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_Update(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->Update();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_DoMainGameUpdate(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->DoMainGameUpdate();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_CreateWorld(void * jarg1) {
  string arg1 ;
  string *argp1 ;
  
  argp1 = (string *)jarg1; 
  if (!argp1) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null string", 0);
    return ;
  }
  arg1 = *argp1; 
  GameWorld::CreateWorld(arg1);
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_GetWidth(void * jarg1) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (int)(arg1)->GetWidth();
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_GetHeight(void * jarg1) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (int)(arg1)->GetHeight();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_ComputeNewCamera(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->ComputeNewCamera();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SetCameraScrollSpeed(void * jarg1, float jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  float arg2 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (float)jarg2; 
  (arg1)->SetCameraScrollSpeed(arg2);
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_GetCameraX(void * jarg1) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (int)(arg1)->GetCameraX();
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_GetCameraY(void * jarg1) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (int)(arg1)->GetCameraY();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SetCameraShake__SWIG_0(void * jarg1, unsigned int jarg2, int jarg3) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool arg2 ;
  int arg3 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = jarg2 ? true : false; 
  arg3 = (int)jarg3; 
  (arg1)->SetCameraShake(arg2,arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SetCameraShake__SWIG_1(void * jarg1, unsigned int jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool arg2 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = jarg2 ? true : false; 
  (arg1)->SetCameraShake(arg2);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_TransformWorldToView(void * jarg1, void * jarg2, void * jarg3) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  int *arg2 = 0 ;
  int *arg3 = 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (int *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "int & type is null", 0);
    return ;
  } 
  arg3 = (int *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "int & type is null", 0);
    return ;
  } 
  (arg1)->TransformWorldToView(*arg2,*arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_TransformViewToScreen(void * jarg1, void * jarg2, void * jarg3) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  int *arg2 = 0 ;
  int *arg3 = 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (int *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "int & type is null", 0);
    return ;
  } 
  arg3 = (int *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "int & type is null", 0);
    return ;
  } 
  (arg1)->TransformViewToScreen(*arg2,*arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_ShowText__SWIG_0(void * jarg1, char * jarg2, char * jarg3, unsigned int jarg4) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  bool arg4 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (char *)jarg2; 
  arg3 = (char *)jarg3; 
  arg4 = jarg4 ? true : false; 
  (arg1)->ShowText((char const *)arg2,(char const *)arg3,arg4);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_ShowText__SWIG_1(void * jarg1, char * jarg2, char * jarg3) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (char *)jarg2; 
  arg3 = (char *)jarg3; 
  (arg1)->ShowText((char const *)arg2,(char const *)arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_ShowText__SWIG_2(void * jarg1, char * jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  char *arg2 = (char *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = (char *)jarg2; 
  (arg1)->ShowText((char const *)arg2);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SnapCamera(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->SnapCamera();
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameWorld_GetAiFitnessScore(void * jarg1) {
  int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  int result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (int)(arg1)->GetAiFitnessScore();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_AllowPlayerOffscreen(void * jarg1, unsigned int jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool arg2 ;
  
  arg1 = (GameWorld *)jarg1; 
  arg2 = jarg2 ? true : false; 
  (arg1)->AllowPlayerOffscreen(arg2);
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameWorld_PlayerAllowedOffscreen(void * jarg1) {
  unsigned int jresult ;
  GameWorld *arg1 = (GameWorld *) 0 ;
  bool result;
  
  arg1 = (GameWorld *)jarg1; 
  result = (bool)(arg1)->PlayerAllowedOffscreen();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SaveWorld__SWIG_0(void * jarg1, void * jarg2) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  string arg2 ;
  string *argp2 ;
  
  arg1 = (GameWorld *)jarg1; 
  argp2 = (string *)jarg2; 
  if (!argp2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "Attempt to dereference null string", 0);
    return ;
  }
  arg2 = *argp2; 
  (arg1)->SaveWorld(arg2);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameWorld_SaveWorld__SWIG_1(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  (arg1)->SaveWorld();
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_GameWorld(void * jarg1) {
  GameWorld *arg1 = (GameWorld *) 0 ;
  
  arg1 = (GameWorld *)jarg1; 
  delete arg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_GameState_GetInstance() {
  void * jresult ;
  GameState *result = 0 ;
  
  result = (GameState *)GameState::GetInstance();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_SetInstance(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  GameState::SetInstance(arg1);
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_CreateInstance() {
  GameState::CreateInstance();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_FreeInstance() {
  GameState::FreeInstance();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_Shutdown(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->Shutdown();
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameState_Init(void * jarg1, int jarg2, void * jarg3) {
  unsigned int jresult ;
  GameState *arg1 = (GameState *) 0 ;
  int arg2 ;
  char **arg3 ;
  bool result;
  
  arg1 = (GameState *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (char **)jarg3; 
  result = (bool)(arg1)->Init(arg2,(char const *(*))arg3);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_RunMainLoop_BlockingHelper(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->RunMainLoop_BlockingHelper();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_ProcessEvents(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->ProcessEvents();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_TickIfNeeded(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->TickIfNeeded();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_Tick(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->Tick();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_UpdateDebugPausing(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->UpdateDebugPausing();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_SetRandomSeed(void * jarg1, int jarg2) {
  GameState *arg1 = (GameState *) 0 ;
  int arg2 ;
  
  arg1 = (GameState *)jarg1; 
  arg2 = (int)jarg2; 
  (arg1)->SetRandomSeed(arg2);
}


SWIGEXPORT int SWIGSTDCALL CSharp_GameState_GetRandomSeed(void * jarg1) {
  int jresult ;
  GameState *arg1 = (GameState *) 0 ;
  int result;
  
  arg1 = (GameState *)jarg1; 
  result = (int)((GameState const *)arg1)->GetRandomSeed();
  jresult = result; 
  return jresult;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameState_IsPlayingBackDemo(void * jarg1) {
  unsigned int jresult ;
  GameState *arg1 = (GameState *) 0 ;
  bool result;
  
  arg1 = (GameState *)jarg1; 
  result = (bool)(arg1)->IsPlayingBackDemo();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_SignalGameExit(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->SignalGameExit();
}


SWIGEXPORT void SWIGSTDCALL CSharp_GameState_SignalEndCurrentMode(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  (arg1)->SignalEndCurrentMode();
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_GameState_ShouldExit(void * jarg1) {
  unsigned int jresult ;
  GameState *arg1 = (GameState *) 0 ;
  bool result;
  
  arg1 = (GameState *)jarg1; 
  result = (bool)(arg1)->ShouldExit();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_GameState(void * jarg1) {
  GameState *arg1 = (GameState *) 0 ;
  
  arg1 = (GameState *)jarg1; 
  delete arg1;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Shape(void * jarg1) {
  Shape *arg1 = (Shape *) 0 ;
  
  arg1 = (Shape *)jarg1; 
  delete arg1;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Shape_x_set(void * jarg1, double jarg2) {
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  
  arg1 = (Shape *)jarg1; 
  arg2 = (double)jarg2; 
  if (arg1) (arg1)->x = arg2;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Shape_x_get(void * jarg1) {
  double jresult ;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  arg1 = (Shape *)jarg1; 
  result = (double) ((arg1)->x);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Shape_y_set(void * jarg1, double jarg2) {
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  
  arg1 = (Shape *)jarg1; 
  arg2 = (double)jarg2; 
  if (arg1) (arg1)->y = arg2;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Shape_y_get(void * jarg1) {
  double jresult ;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  arg1 = (Shape *)jarg1; 
  result = (double) ((arg1)->y);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Shape_move(void * jarg1, double jarg2, double jarg3) {
  Shape *arg1 = (Shape *) 0 ;
  double arg2 ;
  double arg3 ;
  
  arg1 = (Shape *)jarg1; 
  arg2 = (double)jarg2; 
  arg3 = (double)jarg3; 
  (arg1)->move(arg2,arg3);
}


SWIGEXPORT double SWIGSTDCALL CSharp_Shape_area(void * jarg1) {
  double jresult ;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  arg1 = (Shape *)jarg1; 
  result = (double)(arg1)->area();
  jresult = result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Shape_perimeter(void * jarg1) {
  double jresult ;
  Shape *arg1 = (Shape *) 0 ;
  double result;
  
  arg1 = (Shape *)jarg1; 
  result = (double)(arg1)->perimeter();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Shape_nshapes_set(int jarg1) {
  int arg1 ;
  
  arg1 = (int)jarg1; 
  Shape::nshapes = arg1;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Shape_nshapes_get() {
  int jresult ;
  int result;
  
  result = (int)Shape::nshapes;
  jresult = result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Circle(double jarg1) {
  void * jresult ;
  double arg1 ;
  Circle *result = 0 ;
  
  arg1 = (double)jarg1; 
  result = (Circle *)new Circle(arg1);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Circle_area(void * jarg1) {
  double jresult ;
  Circle *arg1 = (Circle *) 0 ;
  double result;
  
  arg1 = (Circle *)jarg1; 
  result = (double)(arg1)->area();
  jresult = result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Circle_perimeter(void * jarg1) {
  double jresult ;
  Circle *arg1 = (Circle *) 0 ;
  double result;
  
  arg1 = (Circle *)jarg1; 
  result = (double)(arg1)->perimeter();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Circle(void * jarg1) {
  Circle *arg1 = (Circle *) 0 ;
  
  arg1 = (Circle *)jarg1; 
  delete arg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Square(double jarg1) {
  void * jresult ;
  double arg1 ;
  Square *result = 0 ;
  
  arg1 = (double)jarg1; 
  result = (Square *)new Square(arg1);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Square_area(void * jarg1) {
  double jresult ;
  Square *arg1 = (Square *) 0 ;
  double result;
  
  arg1 = (Square *)jarg1; 
  result = (double)(arg1)->area();
  jresult = result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_Square_perimeter(void * jarg1) {
  double jresult ;
  Square *arg1 = (Square *) 0 ;
  double result;
  
  arg1 = (Square *)jarg1; 
  result = (double)(arg1)->perimeter();
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Square(void * jarg1) {
  Square *arg1 = (Square *) 0 ;
  
  arg1 = (Square *)jarg1; 
  delete arg1;
}


SWIGEXPORT GameMode * SWIGSTDCALL CSharp_GameWorld_SWIGUpcast(GameWorld *jarg1) {
    return (GameMode *)jarg1;
}

SWIGEXPORT Shape * SWIGSTDCALL CSharp_Circle_SWIGUpcast(Circle *jarg1) {
    return (Shape *)jarg1;
}

SWIGEXPORT Shape * SWIGSTDCALL CSharp_Square_SWIGUpcast(Square *jarg1) {
    return (Shape *)jarg1;
}

#ifdef __cplusplus
}
#endif

