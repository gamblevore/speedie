
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


    // C++ version of Jeebox!
        // Use this instead of jeebox_api.h if possible.

    // Automated RefCounting!:
        // Does away with manual refcounting! VERY error-prone.
        // It's a very bad experience trying to manual refcount!


#include "jeebox_api.h"
#include <stdlib.h>
#include <string>
#include <string.h>


namespace Jeebox {


class String;
class Message;
class Syntax;
class MessageIterator;



class Syntax {
// no need refcount. they always exist and are never destroyed.
public:
    jbsyntax _self;
    __nodebug operator jbsyntax() const { return _self; }
    __nodebug Syntax (jbsyntax s) { _self = s; }
    __nodebug String name() const;
    __nodebug String longname() const;
    __nodebug Message create (const String& Name);
};


class String {
public:
    jbstring* _self;
    __nodebug ~String () {jb_decr(_self);}
    __nodebug String () {
        jb_incr(_self = nullptr);
    }
    __nodebug String (jbstring* s) {
        jb_incr(_self = s);
    }
    __nodebug String (const char* s) {
        jb_incr(_self = jb_cstr(s));
    }
    __nodebug String (const char* s, int n) {
        jb_incr(_self = jb_str(s,n,0,0));
    }
    __nodebug String (const std::string& s) {
        jb_incr(_self = jb_str(s.data(),(int)s.size(),0,0));
    }
    
    __nodebug String (const String &s) {
        jb_incr(_self = s._self);
    }
    __nodebug String& operator = (const String &s) {
        jbstring* Old = _self;
        jb_incr(_self = s._self);
        jb_decr(Old);
        return *this;
    }
    
    __nodebug Message     parse  (const String& Path) const;
    __nodebug Message     parse  () const;
    __nodebug void        print () const      {jb_string_print(_self);}
    __nodebug void        printline () const  {jb_string_printline(_self);}
    __nodebug const char* address ()const     {return jb_string_address(_self);}
    __nodebug int         length () const     {return jb_string_length(_self);}
    __nodebug String      copy () const       {return jb_string_copy(_self);}
    __nodebug String      escape () const     {return jb_string_escape(_self);}
    __nodebug String      compress () const     {return jb_string_compress(_self);}
    __nodebug String      decompress () const     {return jb_string_decompress(_self);}
__nodebug void        fwrite (FILE* f) const  {std::fwrite(address(), length(), 1, f);}
    

//                
    __nodebug std::string std () const        {return std::string(address(), length());}
__nodebug bool operator==(const char* s) const{return !strncmp(s, address(), length());}
__nodebug bool operator!=(const char* s) const{return !(*this == s);}
    __nodebug operator jbstring*() const      {if (length()) return _self; return 0;}
    __nodebug operator std::string() const    {return std();}
    char operator[] (int index)  const        {return jb_string_address(_self)[index];} 
};


class Message {
public:
    jbmessage* _self;
    __nodebug operator jbmessage*() const { return _self; }
    
    __nodebug ~Message () {
        jb_decr(_self);
    }
    __nodebug Message (jbmessage* s) {
        jb_incr(_self = s);
    }
    __nodebug Message () {
        jb_incr(_self = nullptr);
    }
    __nodebug Message (const Message &s) {
        jb_incr(_self = s._self);
    } 
    __nodebug Message& operator = (const Message &s) {
        jbmessage* Old = _self;
        jb_incr(_self = s._self);
        jb_decr(Old);
        return *this;
    }

    __nodebug MessageIterator begin () const; 
    __nodebug MessageIterator end () const;
    

    __nodebug Message create (const Syntax& X, const String& Name=(const char*)0) {
        return jb_msg_create(_self, X._self, Name._self);
    }

    __nodebug Syntax  type () const    {return jb_msg_func(_self);}
    __nodebug String  name () const    {return jb_msg_name(_self);}
    __nodebug int     position() const {return jb_msg_position(_self);}
    __nodebug void*   tag () const     {return jb_msg_tag(_self);}
    __nodebug Message first() const    {return jb_msg_first(_self);}
    __nodebug Message last() const     {return jb_msg_last(_self);}
    __nodebug Message prev() const     {return jb_msg_prev(_self);}
    __nodebug Message next() const     {return jb_msg_next(_self);}
    __nodebug Message parent() const   {return jb_msg_parent(_self);}

__nodebug Message first(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_expect(jb_msg_first(_self), Type, Name, _self);}
__nodebug Message next(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_expect(jb_msg_next(_self), Type, Name, _self);}
__nodebug Message first_(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_expect(jb_msg_first(_self), Type, Name, nullptr);}
__nodebug Message next_(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_expect(jb_msg_next(_self), Type, Name, nullptr);}
__nodebug Message item(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_access(_self, Type, Name, true);}
__nodebug Message item_(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_access(_self, Type, Name, false);}

__nodebug Message match(const Syntax& Type, const String& Name=(const char*)0) const    {return jb_msg_expect(_self, Type, Name, nullptr);}
	__nodebug void error(const String& Msg) const {return jb_msg_error(_self, Msg);}

    __nodebug Message flatnext() const			{return jb_msg_flatnext(_self);}
    __nodebug Message flatafter() const			{return jb_msg_flatafter(_self);}
    __nodebug Message copy(const Message& l) const {return jb_msg_copy(_self, l);}
    __nodebug Message copy() const				{return jb_msg_copy(_self, 0);}
    __nodebug String  render(int Mode = 0) const {return jb_msg_render(_self, Mode);}
    __nodebug String  render_jbin() const		{return jb_msg_render(_self, 1);}
    __nodebug Message root() const				{return jb_msg_root(_self);}
	__nodebug String  ast() const				{return jb_msg_ast(_self);}
	__nodebug Message parseast() const			{return jb_msg_parseast(_self);}

    __nodebug void    remove()    {return jb_msg_remove(_self);}
    
    __nodebug void    type (const Syntax& s)   {jb_msg_funcset(_self, s._self);}
    __nodebug void    name (const String& s)   {jb_msg_nameset(_self, s._self);}
    __nodebug void    position(int s)          {jb_msg_positionset(_self, s);}
    __nodebug void    tag (void* s)            {jb_msg_tagset(_self, s);}
    __nodebug void    first(const Message& s)  {jb_msg_firstset(_self, s._self);}
    __nodebug void    last(const Message& s)   {jb_msg_lastset(_self, s._self);}
    __nodebug void    prev(const Message& s)   {jb_msg_prevset(_self, s._self);}
    __nodebug void    next(const Message& s)   {jb_msg_nextset(_self, s._self);}
        
    __nodebug void    append(const Message& s)   {last(s);}
    
    __nodebug int64    nameint()                 {return jb_string_int(jb_msg_name(_self),_self);}
    __nodebug double namefloat()               {return jb_string_float(jb_msg_name(_self),_self);}

};

__nodebug Message String::parse () const {
    return jb_string_parse(_self, nullptr);
}

__nodebug Message String::parse (const String& Path) const {
    return jb_string_parse(_self, Path._self);
}

__nodebug String Syntax::name() const {
    return jb_syx_name(_self);
}
__nodebug String Syntax::longname() const {
    return jb_syx_longname(_self);
}
__nodebug Message Syntax::create (const String& Name) {
    return jb_msg_create(nullptr, _self, Name._self);
}
__nodebug Message errors() {
    return jb_errors();
}

__nodebug bool ok() {
    return jb_ok();
}
__nodebug Syntax syntax(const String& name) {
    return jb_syntax(name._self);
}

__nodebug String readfile(_cstring path, bool AllowMissingFile=false) {
    return jb_readfile(path, AllowMissingFile);
}

__nodebug Message parsefile(_cstring path, bool AllowMissingFile=false) {
    String Data = jb_readfile(path, AllowMissingFile);
    return Data.parse(path);
}





static void string_free(void* addr, void* Tag) {
    free(addr);
}

__nodebug String string_owned(const char* Addr, int n) {
    return jb_str(Addr, n, (void*)string_free, (void*)Addr);
}


__nodebug String string_copy(const char* Addr, int n) {
    return String(Addr, n).copy();
}



/// C++ iterators...
class MessageIterator {
public:
    __nodebug MessageIterator (jbmessage* M) {
        msg = M;
    }
 
    __nodebug bool operator != (const MessageIterator& other) const {
        return msg != other.msg;
    }
 
    __nodebug Message operator* () const {
        return msg;
    }
 
    __nodebug const MessageIterator& operator++ () {
        if (msg) { // nil is acceptable;
            msg = jb_msg_next(msg);
        }
        return *this;
    }
 
private:
    jbmessage* msg;
};


__nodebug MessageIterator Message::begin () const {
    return MessageIterator( _self ? jb_msg_first(_self) : 0 );
}

__nodebug MessageIterator Message::end () const {
    return MessageIterator( 0 );
}


}


