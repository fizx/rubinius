#ifndef RBX_BUILTIN_WEAKREF_HPP
#define RBX_BUILTIN_WEAKREF_HPP

#include "builtin/object.hpp"
#include "builtin/exception.hpp"
#include "type_info.hpp"

namespace rubinius {
  class WeakRef : public Object {
  public:
    const static object_type type = WeakRefType;

  private:
    Object* object_;

  public:

    // Ruby.primitive+ :weakref_object
    Object* object() {
      return object_;
    }

    void set_object(Object* obj) {
      object_ = obj;
    }

    static void init(STATE);

    // Ruby.primitive+ :weakref_new
    static WeakRef* create(STATE, Object* obj);

    bool alive_p() {
      return object_->reference_p();
    }

    class Info : public TypeInfo {
    public:
      Info(object_type type, bool cleanup = false) : TypeInfo(type, cleanup) { }
      virtual void mark(Object* obj, ObjectMark& mark);
      virtual void auto_mark(Object* obj, ObjectMark& mark) {}
    };
  };
}

#endif
