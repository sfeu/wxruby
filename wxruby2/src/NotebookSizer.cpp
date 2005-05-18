/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIG_NOINCLUDE
#define SWIG_DIRECTORS

#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};                                                    
#endif

/* ruby.swg */
/* Implementation : RUBY */
#define SWIGRUBY 1

#include "ruby.h"

/* Flags for pointer conversion */
#define SWIG_POINTER_EXCEPTION     0x1
#define SWIG_POINTER_DISOWN        0x2

#define NUM2USHRT(n) (\
    (0 <= NUM2UINT(n) && NUM2UINT(n) <= USHRT_MAX)\
    ? (unsigned short) NUM2UINT(n) \
    : (rb_raise(rb_eArgError, "integer %d out of range of `unsigned short'",\
               NUM2UINT(n)), (short)0)\
)

#define NUM2SHRT(n) (\
    (SHRT_MIN <= NUM2INT(n) && NUM2INT(n) <= SHRT_MAX)\
    ? (short)NUM2INT(n)\
    : (rb_raise(rb_eArgError, "integer %d out of range of `short'",\
               NUM2INT(n)), (short)0)\
)

/* Ruby 1.7 defines NUM2LL(), LL2NUM() and ULL2NUM() macros */
#ifndef NUM2LL
#define NUM2LL(x) NUM2LONG((x))
#endif
#ifndef LL2NUM
#define LL2NUM(x) INT2NUM((long) (x))
#endif
#ifndef ULL2NUM
#define ULL2NUM(x) UINT2NUM((unsigned long) (x))
#endif

/* Ruby 1.7 doesn't (yet) define NUM2ULL() */
#ifndef NUM2ULL
#ifdef HAVE_LONG_LONG
#define NUM2ULL(x) rb_num2ull((x))
#else
#define NUM2ULL(x) NUM2ULONG(x)
#endif
#endif

/*
 * Need to be very careful about how these macros are defined, especially
 * when compiling C++ code or C code with an ANSI C compiler.
 *
 * VALUEFUNC(f) is a macro used to typecast a C function that implements
 * a Ruby method so that it can be passed as an argument to API functions
 * like rb_define_method() and rb_define_singleton_method().
 *
 * VOIDFUNC(f) is a macro used to typecast a C function that implements
 * either the "mark" or "free" stuff for a Ruby Data object, so that it
 * can be passed as an argument to API functions like Data_Wrap_Struct()
 * and Data_Make_Struct().
 */
 
#ifdef __cplusplus
#  ifndef RUBY_METHOD_FUNC /* These definitions should work for Ruby 1.4.6 */
#    define VALUEFUNC(f) ((VALUE (*)()) f)
#    define VOIDFUNC(f)  ((void (*)()) f)
#  else
#    ifndef ANYARGS /* These definitions should work for Ruby 1.6 */
#      define VALUEFUNC(f) ((VALUE (*)()) f)
#      define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)
#    else /* These definitions should work for Ruby 1.7 */
#      define VALUEFUNC(f) ((VALUE (*)(ANYARGS)) f)
#      define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)
#    endif
#  endif
#else
#  define VALUEFUNC(f) (f)
#  define VOIDFUNC(f) (f)
#endif

typedef struct {
  VALUE klass;
  VALUE mImpl;
  void  (*mark)(void *);
  void  (*destroy)(void *);
} swig_class;

/* Don't use for expressions have side effect */
#ifndef RB_STRING_VALUE
#define RB_STRING_VALUE(s) (TYPE(s) == T_STRING ? (s) : (*(volatile VALUE *)&(s) = rb_str_to_str(s)))
#endif
#ifndef StringValue
#define StringValue(s) RB_STRING_VALUE(s)
#endif
#ifndef StringValuePtr
#define StringValuePtr(s) RSTRING(RB_STRING_VALUE(s))->ptr
#endif
#ifndef StringValueLen
#define StringValueLen(s) RSTRING(RB_STRING_VALUE(s))->len
#endif
#ifndef SafeStringValue
#define SafeStringValue(v) do {\
    StringValue(v);\
    rb_check_safe_str(v);\
} while (0)
#endif

#ifndef HAVE_RB_DEFINE_ALLOC_FUNC
#define rb_define_alloc_func(klass, func) rb_define_singleton_method((klass), "new", VALUEFUNC((func)), -1)
#define rb_undef_alloc_func(klass) rb_undef_method(CLASS_OF((klass)), "new")
#endif

/* Contract support */

#define SWIG_contract_assert(expr, msg) if (!(expr)) { rb_raise(rb_eRuntimeError, (char *) msg ); } else


/*************************************************************** -*- c -*-
 * ruby/precommon.swg
 *
 * Rename all exported symbols from common.swg, to avoid symbol
 * clashes if multiple interpreters are included
 *
 ************************************************************************/

#define SWIG_TypeRegister    SWIG_Ruby_TypeRegister
#define SWIG_TypeCheck       SWIG_Ruby_TypeCheck
#define SWIG_TypeCast        SWIG_Ruby_TypeCast
#define SWIG_TypeDynamicCast SWIG_Ruby_TypeDynamicCast
#define SWIG_TypeName        SWIG_Ruby_TypeName
#define SWIG_TypePrettyName  SWIG_Ruby_TypePrettyName
#define SWIG_TypeQuery       SWIG_Ruby_TypeQuery
#define SWIG_TypeClientData  SWIG_Ruby_TypeClientData
#define SWIG_PackData        SWIG_Ruby_PackData 
#define SWIG_UnpackData      SWIG_Ruby_UnpackData 

/* Also rename all exported symbols from rubydef.swig */

/* Common SWIG API */
#define SWIG_ConvertPtr(obj, pp, type, flags) \
  SWIG_Ruby_ConvertPtr(obj, pp, type, flags)
#define SWIG_NewPointerObj(p, type, flags) \
  SWIG_Ruby_NewPointerObj(p, type, flags)
#define SWIG_MustGetPtr(p, type, argnum, flags) \
  SWIG_Ruby_MustGetPtr(p, type, argnum, flags)

/* Ruby-specific SWIG API */

#define SWIG_InitRuntime() \
  SWIG_Ruby_InitRuntime()
#define SWIG_define_class(ty) \
  SWIG_Ruby_define_class(ty)
#define SWIG_NewClassInstance(value, ty) \
  SWIG_Ruby_NewClassInstance(value, ty)
#define SWIG_MangleStr(value) \
  SWIG_Ruby_MangleStr(value)
#define SWIG_CheckConvert(value, ty) \
  SWIG_Ruby_CheckConvert(value, ty)
#define SWIG_NewPackedObj(ptr, sz, ty) \
  SWIG_Ruby_NewPackedObj(ptr, sz, ty)
#define SWIG_ConvertPacked(obj, ptr, sz, ty, flags) \
  SWIG_Ruby_ConvertPacked(obj, ptr, sz, ty, flags)


/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#  if defined(_MSC_VER) || defined(__GNUC__)
#    if defined(STATIC_LINKED)
#      define SWIGEXPORT(a) a
#      define SWIGIMPORT(a) extern a
#    else
#      define SWIGEXPORT(a) __declspec(dllexport) a
#      define SWIGIMPORT(a) extern a
#    endif
#  else
#    if defined(__BORLANDC__)
#      define SWIGEXPORT(a) a _export
#      define SWIGIMPORT(a) a _export
#    else
#      define SWIGEXPORT(a) a
#      define SWIGIMPORT(a) a
#    endif
#  endif
#else
#  define SWIGEXPORT(a) a
#  define SWIGIMPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#  define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#  define SWIGRUNTIME(a) static a
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

typedef struct swig_type_info {
  const char             *name;
  swig_converter_func     converter;
  const char             *str;
  void                   *clientdata;
  swig_dycast_func        dcast;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
} swig_type_info;

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGIMPORT(void *)           SWIG_TypeCast(swig_type_info *, void *);
SWIGIMPORT(swig_type_info *) SWIG_TypeDynamicCast(swig_type_info *, void **);
SWIGIMPORT(const char *)     SWIG_TypeName(const swig_type_info *);
SWIGIMPORT(const char *)     SWIG_TypePrettyName(const swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGIMPORT(void)             SWIG_TypeClientData(swig_type_info *, void *);
SWIGIMPORT(char *)           SWIG_PackData(char *, void *, int);
SWIGIMPORT(char *)           SWIG_UnpackData(char *, void *, int);

#else

static swig_type_info *swig_type_list = 0;
static swig_type_info **swig_type_list_handle = &swig_type_list;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti) {
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = *swig_type_list_handle;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      if (tc->clientdata) ti->clientdata = tc->clientdata;
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = *swig_type_list_handle;
  *swig_type_list_handle = ti;

  /* Build linked lists */
  l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  if (next) next->prev = head;
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty) {
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  do {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
        s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      s->prev = ty;
      return s;
    }
    s = s->next;
  } while (s && (s != ty->next));
  return 0;
}

/* Cast a pointer up an inheritance hierarchy */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) {
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Dynamic pointer casting. Down an inheritance hierarchy */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/* Return the name associated with this type */
SWIGRUNTIME(const char *)
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/* Return the pretty name associated with this type,
   that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME(const char *)
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  We choose
     to print the last name, as it is often (?) the most
     specific. */
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/* 
   Compare two type names skipping the space characters, therefore
   "char*" == "char *" and "Class<int>" == "Class<int >", etc.

   Return 0 when the two name types are equivalent, as in
   strncmp, but skipping ' '.
*/
static int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return *f1 - *f2;
  }
  return (l1 - f1) - (l2 - f2);
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
*/
static int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  int equiv = 0;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (!equiv && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = SWIG_TypeNameComp(nb, ne, tb, te) == 0;
    if (*ne) ++ne;
  }
  return equiv;
}
  

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = *swig_type_list_handle;
  while (ty) {
    if (ty->str && (SWIG_TypeEquiv(ty->str,name))) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata == clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = *swig_type_list_handle;
      while (tc) {
        if ((strcmp(tc->name, equiv->name) == 0))
          SWIG_TypeClientData(tc,clientdata);
        tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}

/* Pack binary data into a string */
SWIGRUNTIME(char *)
SWIG_PackData(char *c, void *ptr, int sz) {
  static char hex[17] = "0123456789abcdef";
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  register unsigned char uu;
  for (; u != eu; ++u) {
    uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/* Unpack binary data from a string */
SWIGRUNTIME(char *)
SWIG_UnpackData(char *c, void *ptr, int sz) {
  register unsigned char uu = 0;
  register int d;
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    *u = uu;
  }
  return c;
}

#endif

#ifdef __cplusplus
}
#endif

/* rubydec.swg -*- c -*- */
#ifdef __cplusplus
extern "C" {
#endif

SWIGIMPORT(void)   SWIG_Ruby_InitRuntime(void);
SWIGIMPORT(void)   SWIG_Ruby_define_class(swig_type_info *);
SWIGIMPORT(VALUE)  SWIG_Ruby_NewPointerObj(void *, swig_type_info *, int);
SWIGIMPORT(VALUE)  SWIG_Ruby_NewClassInstance(VALUE, swig_type_info *);
SWIGIMPORT(char *) SWIG_Ruby_MangleStr(VALUE);
SWIGIMPORT(int)    SWIG_Ruby_ConvertPtr(VALUE, void**, swig_type_info *, int);
SWIGIMPORT(void *) SWIG_Ruby_MustGetPtr(VALUE, swig_type_info *, int, int);
SWIGIMPORT(int)    SWIG_Ruby_CheckConvert(VALUE, swig_type_info *);
SWIGIMPORT(VALUE)  SWIG_Ruby_NewPackedObj(void *ptr, int sz, swig_type_info *type);
SWIGIMPORT(void)   SWIG_Ruby_ConvertPacked(VALUE obj, void *ptr, int sz, swig_type_info *ty, int flags);

#ifdef __cplusplus
}
#endif


/* -------- TYPES TABLE (BEGIN) -------- */

#define  SWIGTYPE_p_wxNotebookSizer swig_types[0] 
#define  SWIGTYPE_p_wxNotebook swig_types[1] 
static swig_type_info *swig_types[3];

/* -------- TYPES TABLE (END) -------- */

#define SWIG_init    Init_wxNotebookSizer
#define SWIG_name    "WxNotebookSizer"

static VALUE alive = Qnil;

static VALUE mWxNotebookSizer;
   extern VALUE mWx;

static void SWIG_AsVal(VALUE obj, int *val)
{
    *val = (int) NUM2INT(obj);
}


#  undef GetClassName
#  undef GetClassInfo
#  undef Yield
#  undef GetMessage
#  undef FindWindow
#  undef GetCharWidth
#  undef DrawText
#  undef StartDoc
#  undef CreateDialog
#  undef Sleep
#  undef _
#  undef Connect
#  undef connect

#include <wx/wx.h>
#include <wx/dcbuffer.h>

void GcMarkDeleted(void *);
bool GcIsDeleted(void *);
void GcMapPtrToValue(void *ptr, VALUE val);
VALUE GcGetValueFromPtr(void *ptr);
void GcFreefunc(void *);


#include <wx/datetime.h>


extern swig_class cWxSizer;
swig_class cWxNotebookSizer;
static void free_wxNotebookSizer(wxNotebookSizer *);
/***********************************************************************
 * director.swg
 *
 * This file contains support for director classes that proxy
 * method calls from C++ to Ruby extensions.
 *
 * Author : Lyle Johnson (lyle@users.sourceforge.net)
 *          Based on the original Python implementation by
 *          Mark Rose (mrose@stm.lbl.gov).
 ************************************************************************/

#ifdef __cplusplus

#include <string>

namespace Swig {
  struct body_args {
    VALUE recv;
    ID id;
    int argc;
    VALUE *argv;
  };

  /* Base class for director exceptions */
  class DirectorException {
    protected:
      VALUE swig_error;
    protected:
      DirectorException(VALUE error=Qnil) : swig_error(error) {}
    public:
      VALUE getType() const  { 
        return CLASS_OF(swig_error); 
      }
      VALUE getError() const {
        return swig_error;
      }
      virtual ~DirectorException() {}
  };

  /* Type mismatch in the return value from a Ruby method call */
  class DirectorTypeMismatchException : public Swig::DirectorException {
    public:
      DirectorTypeMismatchException(const char *msg="") {
        VALUE str = rb_str_new2("Swig director type mismatch: ");
        rb_str_concat(str, rb_str_new2(msg));
        swig_error = rb_exc_new3(rb_eTypeError, str);
      }
  };

  /* Any Ruby exception that occurs during a director method call */
  class DirectorMethodException : public Swig::DirectorException {
    public:
      DirectorMethodException(VALUE error) : Swig::DirectorException(error) {}
  };

  /* Attempted to call a pure virtual method via a director method */
  class DirectorPureVirtualException : public Swig::DirectorException {};


  /* Simple thread abstraction for pthreads on win32 */
#ifdef __THREAD__
#define __PTHREAD__
#if defined(_WIN32) || defined(__WIN32__)
#define pthread_mutex_lock EnterCriticalSection
#define pthread_mutex_unlock LeaveCriticalSection
#define pthread_mutex_t CRITICAL_SECTION
#define MUTEX_INIT(var) CRITICAL_SECTION var
#else
#include <pthread.h>
#define MUTEX_INIT(var) pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER 
#endif
#endif

  /* director base class */
  class Director {
    private:
      /* pointer to the wrapped Ruby object */
      VALUE swig_self;
      /* flag indicating whether the object is owned by Ruby or c++ */
      mutable bool swig_disown_flag;
      /* shared flag for breaking recursive director calls */
      static bool swig_up;

#ifdef __PTHREAD__
      /* locks for sharing the swig_up flag in a threaded environment */
      static pthread_mutex_t swig_mutex_up;
      static bool swig_mutex_active;
      static pthread_t swig_mutex_thread;
#endif

      /* reset the swig_up flag once the routing direction has been determined */
#ifdef __PTHREAD__
      void swig_clear_up() const { 
        Swig::Director::swig_up = false; 
        Swig::Director::swig_mutex_active = false;
        pthread_mutex_unlock(&swig_mutex_up);
      }
#else
      void swig_clear_up() const { 
        Swig::Director::swig_up = false; 
      }
#endif

    public:
      /* wrap a Ruby object, optionally taking ownership */
      Director(VALUE self, bool disown) : swig_self(self), swig_disown_flag(disown) {

#ifdef wxDEBUG
    printf("NotebookSizer.cpp" " new Director %p\n", this);
    fflush(stdout);
#endif
    GcMapPtrToValue(this,self);
      }

      /* discard our reference at destruction */
      virtual ~Director() {

#ifdef wxDEBUG
    printf("NotebookSizer.cpp" " ~Director %p\n", this);
    fflush(stdout);
#endif
    GcMarkDeleted(this);
      }

      /* return a pointer to the wrapped Ruby object */
      VALUE swig_get_self() const { 
        return swig_self; 
      }

      /* get the swig_up flag to determine if the method call should be routed
       * to the c++ base class or through the wrapped Ruby object
       */
#ifdef __PTHREAD__
      bool swig_get_up() const { 
        if (Swig::Director::swig_mutex_active) {
          if (pthread_equal(Swig::Director::swig_mutex_thread, pthread_self())) {
            bool up = swig_up;
            swig_clear_up();
            return up;
          }
        }
        return false;
      }
#else 
      bool swig_get_up() const { 
        bool up = swig_up;
        swig_up = false;
        return up;
      }
#endif

      /* set the swig_up flag if the next method call should be directed to
       * the c++ base class rather than the wrapped Ruby object
       */
#ifdef __PTHREAD__
      void swig_set_up() const { 
        pthread_mutex_lock(&Swig::Director::swig_mutex_up);
        Swig::Director::swig_mutex_thread = pthread_self();
        Swig::Director::swig_mutex_active = true;
        Swig::Director::swig_up = true;
      }
#else 
      void swig_set_up() const { 
        Swig::Director::swig_up = true; 
      }
#endif

      /* acquire ownership of the wrapped Ruby object (the sense of "disown"
       * is from Ruby) */
      void swig_disown() const { 
        if (!swig_disown_flag) { 
          swig_disown_flag = true;
        } 
      }
  };

//  bool Swig::Director::swig_up = false;

#ifdef __PTHREAD__
  MUTEX_INIT(Swig::Director::swig_mutex_up);
  pthread_t Swig::Director::swig_mutex_thread;
  bool Swig::Director::swig_mutex_active = false;
#endif

}

#endif /* __cplusplus */




/* ---------------------------------------------------
 * C++ director class methods
 * --------------------------------------------------- */

#include "NotebookSizer.h"

#ifdef HAVE_RB_DEFINE_ALLOC_FUNC
static VALUE
_wrap_wxNotebookSizer_allocate(VALUE self) {
#else
    static VALUE
    _wrap_wxNotebookSizer_allocate(int argc, VALUE *argv, VALUE self) {
#endif
        
        
        VALUE vresult = SWIG_NewClassInstance(self, SWIGTYPE_p_wxNotebookSizer);
#ifndef HAVE_RB_DEFINE_ALLOC_FUNC
        rb_obj_call_init(vresult, argc, argv);
#endif
        return vresult;
    }
    

static VALUE
_wrap_new_wxNotebookSizer(int argc, VALUE *argv, VALUE self) {
    wxNotebook *arg1 = (wxNotebook *) 0 ;
    wxNotebookSizer *result;
    
    if ((argc < 1) || (argc > 1))
    rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
    SWIG_ConvertPtr(argv[0], (void **) &arg1, SWIGTYPE_p_wxNotebook, 1);
    result = (wxNotebookSizer *)new wxNotebookSizer(arg1);
    DATA_PTR(self) = result;
    return self;
}


static VALUE
_wrap_wxNotebookSizer_GetNotebook(int argc, VALUE *argv, VALUE self) {
    wxNotebookSizer *arg1 = (wxNotebookSizer *) 0 ;
    wxNotebook *result;
    VALUE vresult = Qnil;
    
    if ((argc < 0) || (argc > 0))
    rb_raise(rb_eArgError, "wrong # of arguments(%d for 0)",argc);
    SWIG_ConvertPtr(self, (void **) &arg1, SWIGTYPE_p_wxNotebookSizer, 1);
    result = (wxNotebook *)(arg1)->GetNotebook();
    
    vresult = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_wxNotebook,0);
    return vresult;
}


static void
free_wxNotebookSizer(wxNotebookSizer *arg1) {
    //delete arg1;
}

/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_wxNotebookSizer[] = {{"_p_wxNotebookSizer", 0, "wxNotebookSizer *", 0, 0, 0, 0},{"_p_wxNotebookSizer", 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};
static swig_type_info _swigt__p_wxNotebook[] = {{"_p_wxNotebook", 0, "wxNotebook *", 0, 0, 0, 0},{"_p_wxNotebook", 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};

static swig_type_info *swig_types_initial[] = {
_swigt__p_wxNotebookSizer, 
_swigt__p_wxNotebook, 
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */


#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(void) Init_wxNotebookSizer(void) {
static bool initialized;
if(initialized) return;
initialized = true;
    int i;
    
    SWIG_InitRuntime();
mWxNotebookSizer = mWx;
    
    for (i = 0; swig_types_initial[i]; i++) {
        swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
        SWIG_define_class(swig_types[i]);
    }
    
    
    extern void Init_wxSizer();
    Init_wxSizer();
    //extern swig_class cWxSizer;
    cWxNotebookSizer.klass = rb_define_class_under(mWxNotebookSizer, "NotebookSizer", cWxSizer.klass);
    SWIG_TypeClientData(SWIGTYPE_p_wxNotebookSizer, (void *) &cWxNotebookSizer);
    rb_define_alloc_func(cWxNotebookSizer.klass, _wrap_wxNotebookSizer_allocate);
    rb_define_method(cWxNotebookSizer.klass, "initialize", VALUEFUNC(_wrap_new_wxNotebookSizer), -1);
    rb_define_method(cWxNotebookSizer.klass, "get_notebook", VALUEFUNC(_wrap_wxNotebookSizer_GetNotebook), -1);
    cWxNotebookSizer.mark = 0;
    cWxNotebookSizer.destroy = (void (*)(void *)) free_wxNotebookSizer;
}
