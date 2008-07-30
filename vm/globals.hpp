#ifndef RBX_GLOBALS_HPP
#define RBX_GLOBALS_HPP

#define SPECIAL_CLASS_MASK 0x1f
#define SPECIAL_CLASS_SIZE 32


#include "gc_root.hpp"

namespace rubinius {

  struct Globals {

    Roots roots;

    /* This requires some manual work when adding a root, but thats ok.
     * First, add the root to the END of this list. Then add it to
     * the constructor for Globals, again, at the END of the list. */

    /* classes for the core 'types' */
    TypedRoot<Class*> blokctx, cmethod, tuple, module, object, array;
    TypedRoot<Class*> klass, hash, methtbl, bytearray, methctx, blank;
    TypedRoot<Class*> blokenv, bignum, regexp, regexpdata, matchdata;
    TypedRoot<Class*> string, symbol, io, metaclass, symtbl;
    TypedRoot<Class*> nil_class, true_class, false_class, fixnum_class, undef_class;
    TypedRoot<Class*> floatpoint, fastctx, data, nmethod, nmc, task, list, list_node;
    TypedRoot<Class*> channel, thread, staticscope, send_site, selector, lookuptable;
    TypedRoot<Class*> iseq, executable, ffi_ptr, ffi_func, iobuffer;
    TypedRoot<Class*> cmethod_vis;

    /* the primary symbol table */
    TypedRoot<SymbolTable*> symbols;
    TypedRoot<SYMBOL> sym_method_missing;
    TypedRoot<SYMBOL> sym_inherited, sym_opened_class;
    TypedRoot<SYMBOL> sym_from_literal, sym_method_added, sym_s_method_added, sym_init_copy;
    TypedRoot<SYMBOL> sym_plus, sym_minus, sym_equal, sym_nequal, sym_tequal, sym_lt, sym_gt;
    TypedRoot<SYMBOL> sym_initialize;

    TypedRoot<Class*> exception;
    TypedRoot<Class*> exc_arg, exc_segfault;
    TypedRoot<Class*> exc_loe, exc_type, exc_rex;
    TypedRoot<Class*> exc_stack_explosion;
    TypedRoot<Class*> exc_primitive_failure;

    TypedRoot<LookupTable*> external_ivars;
    TypedRoot<Tuple*> scheduled_threads;
    TypedRoot<LookupTable*> errno_mapping;
    TypedRoot<LookupTable*> selectors;
    TypedRoot<OBJECT> config;
    TypedRoot<SYMBOL> sym_send;
    TypedRoot<SYMBOL> sym_public, sym_private, sym_protected, sym_const_missing;
    TypedRoot<SYMBOL> sym_object_id, sym_call;
    TypedRoot<OBJECT> top_scope, on_gc_channel;

    TypedRoot<Module*> vm;
    TypedRoot<Thread*> current_thread;
    TypedRoot<Task*> current_task;
    TypedRoot<OBJECT> main;
    TypedRoot<Class*> dir;

    /* Add new globals above this line. */

    /* Leave this as the last data member always */
    TypedRoot<Class*> special_classes[SPECIAL_CLASS_SIZE];

    Globals() :
      blokctx(&roots), cmethod(&roots), tuple(&roots), module(&roots),
      object(&roots), array(&roots),
      klass(&roots), hash(&roots), methtbl(&roots), bytearray(&roots),
      methctx(&roots), blank(&roots),
      blokenv(&roots), bignum(&roots), regexp(&roots), regexpdata(&roots),
      matchdata(&roots),
      string(&roots), symbol(&roots), io(&roots), metaclass(&roots), symtbl(&roots),
      nil_class(&roots), true_class(&roots), false_class(&roots), fixnum_class(&roots),
      undef_class(&roots),
      floatpoint(&roots), fastctx(&roots), data(&roots), nmethod(&roots), nmc(&roots),
      task(&roots), list(&roots), list_node(&roots), channel(&roots), thread(&roots),
      staticscope(&roots), send_site(&roots), selector(&roots), lookuptable(&roots),
      iseq(&roots), executable(&roots), ffi_ptr(&roots), ffi_func(&roots),
      iobuffer(&roots), cmethod_vis(&roots),
      symbols(&roots),
      sym_method_missing(&roots),
      sym_inherited(&roots), sym_opened_class(&roots),
      sym_from_literal(&roots), sym_method_added(&roots), sym_s_method_added(&roots),
      sym_init_copy(&roots),
      sym_plus(&roots), sym_minus(&roots), sym_equal(&roots), sym_nequal(&roots),
      sym_tequal(&roots), sym_lt(&roots), sym_gt(&roots),
      sym_initialize(&roots),
      exception(&roots),
      exc_arg(&roots), exc_segfault(&roots),
      exc_loe(&roots), exc_type(&roots), exc_rex(&roots),
      exc_stack_explosion(&roots),
      exc_primitive_failure(&roots),
      external_ivars(&roots),
      scheduled_threads(&roots),
      errno_mapping(&roots),
      selectors(&roots),
      config(&roots),
      sym_send(&roots),
      sym_public(&roots), sym_private(&roots), sym_protected(&roots),
      sym_const_missing(&roots),
      sym_object_id(&roots), sym_call(&roots),
      top_scope(&roots), on_gc_channel(&roots),
      vm(&roots),
      current_thread(&roots),
      current_task(&roots),
      main(&roots),
      dir(&roots)

      /* Add initialize of globals above this line. */
    { }
  };
};

#endif