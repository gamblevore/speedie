
/* jeebox-licence:
    By Theodore H. Smith, 2019, theo@jeebox.org
	
    This software is provided 'as-is', without any warranty.
    In no event will the author be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercially, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software.
    2. If you use this software or portions of this software in a product, you
        are required to acknowledge this in at least one of:
        About-window / launch-screen / help-files / read-me-file
    3. Altered source vershions must be plainly marked as such, and must not be
        misrepresented as being the original software.
    4. Any jeebox-licence note may not be removed/altered from any source distribution.
*/


		// API


extern "C" {

		// Types

typedef const char* _cstring;
typedef void* _voidptr;
#ifndef u8
	typedef unsigned char  u8; 
#endif
#ifndef byte
	typedef u8  byte; 
#endif
#ifndef int64
	typedef long long  int64; 
#endif
#ifndef uint64
	typedef unsigned long long  uint64; 
#endif

struct jbobject {int RefCount;};
struct jbmessage : jbobject {};
typedef byte jbsyntax;
struct jbstring : jbobject {};


		// Message functions

jbstring* jb_msg_name(jbmessage* self);
jbsyntax jb_msg_func(jbmessage* self);
int jb_msg_position(jbmessage* self);
_voidptr jb_msg_tag(jbmessage* self);
void jb_msg_nameset(jbmessage* self, jbstring* Result); /* Sets the name. */
void jb_msg_funcset(jbmessage* self, jbsyntax Result); /* Sets the syntactic type */
void jb_msg_positionset(jbmessage* self, int Result); /* Sets the byte-position. Jeebox doesn't use this value other than to store it for you. You might want to set the position if you created some nodes yourself via jb_msg_create. Obviously those nodes wouldn't have a position. */
void jb_msg_tagset(jbmessage* self, _voidptr Result); /* In case you want to attach a user-defined value to the node, to use for your own purposes. */
void jb_msg_firstset(jbmessage* self, jbmessage* Result); /* Inserts 'Result' as the first child, and safely-removes it from it's old tree. You don't need to do anything to keep the next/prev/parent/etc values correct! They are updated for you. Same for all tree-node setters: jb_msg_lastset, jb_msg_prevset, jb_msg_nextset */
void jb_msg_lastset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as the last child. */
void jb_msg_prevset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as our prev-sibling. Does nothing if 'self' has no parent. */
void jb_msg_nextset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as our next-sibling. Does nothing if 'self' has no parent. */
jbmessage* jb_msg_first(jbmessage* self);
jbmessage* jb_msg_last(jbmessage* self);
jbmessage* jb_msg_prev(jbmessage* self);
jbmessage* jb_msg_next(jbmessage* self);
jbmessage* jb_msg_parent(jbmessage* self);
jbmessage* jb_msg_flatnext(jbmessage* self);
jbmessage* jb_msg_flatafter(jbmessage* self);
jbmessage* jb_msg_root(jbmessage* self);
void jb_msg_remove(jbmessage* self); /* Removes the node from the tree. */
jbstring* jb_msg_render(jbmessage* self, int mode); /* Renders the tree as a string! */
jbstring* jb_msg_ast(jbmessage* self);
jbmessage* jb_msg_parseast(jbmessage* self);
jbmessage* jb_msg_copy(jbmessage* self, jbmessage* layer);
jbmessage* jb_msg_create(jbmessage* self, jbsyntax Type, jbstring* Name);
void jb_msg_error(jbmessage* self, jbstring* ErrorMsg); /* Lets you add your own error messages to the tree. */
jbmessage* jb_msg_expect(jbmessage* self, jbsyntax Type, jbstring* name, jbmessage* ErrPlace); /* Test the name and type, (or existance) of a message node. */
jbmessage* jb_msg_access(jbmessage* self, jbsyntax Type, jbstring* name, bool IsError);


		// Syntax functions

jbstring* jb_syx_name(jbsyntax self);
jbstring* jb_syx_longname(jbsyntax self);


		// String functions

_cstring jb_string_address(jbstring* self);
int jb_string_length(jbstring* self);
jbstring* jb_string_compress(jbstring* self);
jbstring* jb_string_decompress(jbstring* self);
jbstring* jb_string_copy(jbstring* self);
jbmessage* jb_string_parse(jbstring* self, jbstring* path);
jbstring* jb_string_escape(jbstring* self);
void jb_string_print(jbstring* self); /* Prints this string to console. Useful for debugging. */
void jb_string_printline(jbstring* self); /* Same as jb_string_print except it ends with a \n. */
int64 jb_string_int(jbstring* self, jbmessage* m);
double jb_string_float(jbstring* self, jbmessage* m);


		// Global functions

jbsyntax jb_syntax(jbstring* name);
jbstring* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag);
jbstring* jb_cstr(_cstring Str); /* Creates a JBString from a c-string. Expects the c-string to remain unchanged until the JBString is freed. */
void jb_delete_(jbobject* obj); /* Deletes the object from memory. Don't call directly, use jb_incr jb_decr. */
jbmessage* jb_errors();
bool jb_ok();
void jb_debug(jbobject* o); /* Prints a description of this object, useful for debugging. */
int jb_init(int Flags);
int jb_shutdown(); /* Frees all memory used by jeebox! */
int jb_version();
jbstring* jb_readfile(_cstring path, bool AllowMissingFile);


		// Jeebox Syntax

#define JB_SyxNil 0;
#define $nil 0
#define JB_SyxArg 1;
#define $arg 1
#define JB_SyxEmb 2;
#define $emb 2
#define JB_SyxType 3;
#define $type 3
#define JB_SyxDecl 4;
#define $decl 4
#define JB_SyxTmp 5;
#define $tmp 5
#define JB_SyxOat 6;
#define $oat 6
#define JB_SyxQues 7;
#define $ques 7
#define JB_SyxCnj 8;
#define $cnj 8
#define JB_SyxOpp 9;
#define $opp 9
#define JB_SyxThg 10;
#define $thg 10
#define JB_SyxSheb 11;
#define $sheb 11
#define JB_SyxSCnj 12;
#define $scnj 12
#define JB_SyxSThg 13;
#define $sthg 13
#define JB_SyxNum 14;
#define $num 14
#define JB_SyxSStr 15;
#define $sstr 15
#define JB_SyxBack 16;
#define $back 16
#define JB_SyxChar 17;
#define $char 17
#define JB_SyxBin 18;
#define $bin 18
#define JB_SyxStr 19;
#define $str 19
#define JB_SyxUnit 20;
#define $unit 20
#define JB_SyxARel 21;
#define $arel 21
#define JB_SyxName 22;
#define $name 22
#define JB_SyxDot 23;
#define $dot 23
#define JB_SyxSDot 24;
#define $sdot 24
#define JB_SyxFunc 25;
#define $func 25
#define JB_SyxBRel 26;
#define $brel 26
#define JB_SyxAdj 27;
#define $adj 27
#define JB_SyxBadj 28;
#define $badj 28
#define JB_SyxAcc 29;
#define $acc 29
#define JB_SyxItem 30;
#define $item 30
#define JB_SyxBra 31;
#define $bra 31
#define JB_SyxList 32;
#define $list 32
#define JB_SyxPrm 33;
#define $prm 33
#define JB_SyxArr 34;
#define $arr 34
#define JB_SyxFile 35;
#define $file 35
#define JB_SyxQuot 36;
#define $quot 36
#define JB_SyxRel 37;
#define $rel 37
#define JB_SyxERel 38;
#define $erel 38
#define JB_SyxTRel 39;
#define $trel 39
#define JB_SyxTril 40;
#define $tril 40
#define JB_Syxpinn 41;
#define $pinn 41
#define JB_Syxbinn 42;
#define $binn 42
#define JB_SyxAsk 43;
#define $ask 43
#define JB_SyxYoda 44;
#define $yoda 44
#define JB_SyxSCom 45;
#define $scom 45
#define JB_SyxMsg 46;
#define $msg 46
#define JB_SyxTodo 47;
#define $todo 47
#define JB_Syxurl 48;
#define $url 48
#define JB_SyxXAtt 49;
#define $xatt 49
#define JB_SyxXML 50;
#define $xml 50
#define JB_SyxXPI 51;
#define $xpi 51
#define JB_SyxXCom 52;
#define $xcom 52
#define JB_SyxXCDT 53;
#define $xcdt 53
#define JB_SyxXTxt 54;
#define $xtxt 54
#define JB_Syxmax 55;
#define $max 55


#ifdef __nodebug
	#undef __nodebug
#endif
#if defined(__linux__)
	#define __nodebug inline __attribute__((__always_inline__)) // __nodebug__ doesn't exist on linux?
#else
	#define __nodebug inline __attribute__((__always_inline__, __nodebug__))
#endif
__nodebug void jb_incr(jbobject* s) {
	if (s) {s->RefCount++;}
}

__nodebug void jb_decr(jbobject* s) {
	if (s) { if (--s->RefCount <= 0) {jb_delete_(s);} }
}

} // end-extern
