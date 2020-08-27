
/* implementation of tree construction functions */

#include "node.h"

#include "nodecode.h"

#include "attrpredef.h"

#include "visitmap.h"

#include "treeact.h"

#ifdef MONITOR
#include "attr_mon_dapto.h"
#include "MONTblStack.h"
#endif

#include <stdlib.h>

#define _USE_OBSTACK 1

/* use of obstack: */

#if _USE_OBSTACK

#include "obstack.h"
static struct obstack TreeSpace;
static void *_TreeBase;

#ifdef __cplusplus
void* NODEPTR_struct::operator new(size_t size)
{
	return obstack_alloc(&TreeSpace, size);
}
#else
#if defined(__STDC__) || defined(__cplusplus)
char* TreeNodeAlloc(int size)
#else
char* TreeNodeAlloc(size) int size;
#endif
{
	return (char *)(obstack_alloc(&TreeSpace, size));
}
#endif

void InitTree()
{
	obstack_init(&TreeSpace);
	_TreeBase=obstack_alloc(&TreeSpace,0);
}

void FreeTree()
{
	obstack_free(&TreeSpace, _TreeBase);
	_TreeBase=obstack_alloc(&TreeSpace,0);
}

#else

#include <stdio.h>

#ifdef __cplusplus
void* NODEPTR_struct::operator new(size_t size)
{
	void *retval = malloc(size);
	if (retval) return retval;
	fprintf(stderr, "*** DEADLY: No more memory.\n");
	exit(1);
}
#else
#if defined(__STDC__) || defined(__cplusplus)
char* TreeNodeAlloc(int size)
#else
char* TreeNodeAlloc(size) int size;
#endif
{
	char *retval = (char *) malloc(size);
	if (retval) return retval;
	fprintf(stderr, "*** DEADLY: No more memory.\n");
	exit(1);
}
#endif

void InitTree() { }

void FreeTree() { }

#endif

#ifdef MONITOR
#define _SETCOORD(node) \
        node->_coord = _coordref ? *_coordref : NoCoord;
#define _COPYCOORD(node) \
        node->_coord = _currn->_desc1->_coord;
#else
#define _SETCOORD(node)
#define _COPYCOORD(node)
#endif
#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mktemplate (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mktemplate (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBtemplate)) return (_currn);
return(NULLNODEPTR);
}/* Mktemplate */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mktask (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mktask (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBtask)) return (_currn);
return(NULLNODEPTR);
}/* Mktask */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkstatement (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkstatement (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBstatement)) return (_currn);
if (IsSymb (_currn, SYMBattr_var)) return (Mkrule_145(_coordref, _currn));
if (IsSymb (_currn, SYMBclass)) return (Mkrule_146(_coordref, _currn));
if (IsSymb (_currn, SYMBcondition)) return (Mkrule_147(_coordref, _currn));
if (IsSymb (_currn, SYMBinclude)) return (Mkrule_148(_coordref, _currn));
if (IsSymb (_currn, SYMBtask)) return (Mkrule_151(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkstatement */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mksources (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mksources (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBsources)) return (_currn);
return(NULLNODEPTR);
}/* Mksources */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mksource (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mksource (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBsource)) return (_currn);
return(NULLNODEPTR);
}/* Mksource */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkset_or_get (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkset_or_get (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBset_or_get)) return (_currn);
return(NULLNODEPTR);
}/* Mkset_or_get */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkreference (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkreference (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBreference)) return (_currn);
return(NULLNODEPTR);
}/* Mkreference */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkProgram (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkProgram (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBProgram)) return (_currn);
if (IsSymb (_currn, SYMBG1)) return (Mkrule_104(_coordref, _currn));
if (IsSymb (_currn, SYMBclass)) return (Mkrule_104(_coordref, _currn));
return(NULLNODEPTR);
}/* MkProgram */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkvariables (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkvariables (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBvariables)) return (_currn);
if (IsSymb (_currn, SYMBvariable)) return (Mkrule_172(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkvariables */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkmetaparams (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkmetaparams (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBmetaparams)) return (_currn);
if (IsSymb (_currn, SYMBmetaparam)) return (Mkrule_93(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkmetaparams */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG2 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG2 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG2)) return (_currn);
if (IsSymb (_currn, SYMBvariable)) return (Mkrule_89(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG1 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG1 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG1)) return (_currn);
if (IsSymb (_currn, SYMBclass)) return (Mkrule_86(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mktasks (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mktasks (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBtasks)) return (_currn);
if (IsSymb (_currn, SYMBtask)) return (Mkrule_153(_coordref, _currn));
return(NULLNODEPTR);
}/* Mktasks */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkcondition (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkcondition (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBcondition)) return (_currn);
return(NULLNODEPTR);
}/* Mkcondition */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkcomparator (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkcomparator (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBcomparator)) return (_currn);
return(NULLNODEPTR);
}/* Mkcomparator */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkcode (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkcode (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBcode)) return (_currn);
return(NULLNODEPTR);
}/* Mkcode */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkos (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkos (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBos)) return (_currn);
return(NULLNODEPTR);
}/* Mkos */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkattr_var (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkattr_var (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBattr_var)) return (_currn);
return(NULLNODEPTR);
}/* Mkattr_var */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkattrs (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkattrs (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBattrs)) return (_currn);
if (IsSymb (_currn, SYMBattr_var)) return (Mkrule_65(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkattrs */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkboolean (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkboolean (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBboolean)) return (_currn);
return(NULLNODEPTR);
}/* Mkboolean */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkmetaparam (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkmetaparam (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBmetaparam)) return (_currn);
return(NULLNODEPTR);
}/* Mkmetaparam */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkfile (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkfile (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBfile)) return (_currn);
return(NULLNODEPTR);
}/* Mkfile */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkdir (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkdir (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBdir)) return (_currn);
return(NULLNODEPTR);
}/* Mkdir */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkvalue (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkvalue (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBvalue)) return (_currn);
if (IsSymb (_currn, SYMBboolean)) return (Mkrule_157(_coordref, _currn));
if (IsSymb (_currn, SYMBextvar)) return (Mkrule_158(_coordref, _currn));
if (IsSymb (_currn, SYMBmetaparam)) return (Mkrule_161(_coordref, _currn));
if (IsSymb (_currn, SYMBos)) return (Mkrule_163(_coordref, _currn));
if (IsSymb (_currn, SYMBreference)) return (Mkrule_165(_coordref, _currn));
if (IsSymb (_currn, SYMBset_or_get)) return (Mkrule_166(_coordref, _currn));
if (IsSymb (_currn, SYMBsource)) return (Mkrule_167(_coordref, _currn));
if (IsSymb (_currn, SYMBsources)) return (Mkrule_168(_coordref, _currn));
if (IsSymb (_currn, SYMBtemplate)) return (Mkrule_169(_coordref, _currn));
if (IsSymb (_currn, SYMBword)) return (Mkrule_171(_coordref, _currn));
if (IsSymb (_currn, SYMBvariable)) return (Mkrule_170(_coordref, _currn));
if (IsSymb (_currn, SYMBnumber)) return (Mkrule_24(_coordref, _currn));
if (IsSymb (_currn, SYMBdir)) return (Mkrule_22(_coordref, _currn));
if (IsSymb (_currn, SYMBfile)) return (Mkrule_20(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkvalue */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mknumber (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mknumber (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBnumber)) return (_currn);
return(NULLNODEPTR);
}/* Mknumber */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkpair (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkpair (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBpair)) return (_currn);
return(NULLNODEPTR);
}/* Mkpair */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mksetting (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mksetting (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBsetting)) return (_currn);
return(NULLNODEPTR);
}/* Mksetting */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkinclude (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkinclude (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBinclude)) return (_currn);
return(NULLNODEPTR);
}/* Mkinclude */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkparam (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkparam (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBparam)) return (_currn);
if (IsSymb (_currn, SYMBattrs)) return (Mkrule_102(_coordref, _currn));
if (IsSymb (_currn, SYMBattr_var)) return (Mkrule_102(_coordref, _currn));
if (IsSymb (_currn, SYMBvariables)) return (Mkrule_103(_coordref, _currn));
if (IsSymb (_currn, SYMBvariable)) return (Mkrule_103(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkparam */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkstatements (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkstatements (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBstatements)) return (_currn);
return(NULLNODEPTR);
}/* Mkstatements */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkclass_name (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkclass_name (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBclass_name)) return (_currn);
return(NULLNODEPTR);
}/* Mkclass_name */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkclass (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkclass (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBclass)) return (_currn);
return(NULLNODEPTR);
}/* Mkclass */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkword (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkword (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBword)) return (_currn);
return(NULLNODEPTR);
}/* Mkword */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkpairs (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkpairs (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBpairs)) return (_currn);
if (IsSymb (_currn, SYMBpair)) return (Mkrule_100(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkpairs */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkcomma (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkcomma (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBcomma)) return (_currn);
return(NULLNODEPTR);
}/* Mkcomma */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkconfig (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkconfig (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBconfig)) return (_currn);
if (IsSymb (_currn, SYMBpair)) return (Mkrule_83(_coordref, _currn));
if (IsSymb (_currn, SYMBpairs)) return (Mkrule_83(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkconfig */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkextvar (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkextvar (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBextvar)) return (_currn);
return(NULLNODEPTR);
}/* Mkextvar */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkwords (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkwords (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBwords)) return (_currn);
return(NULLNODEPTR);
}/* Mkwords */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkvariable (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkvariable (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBvariable)) return (_currn);
return(NULLNODEPTR);
}/* Mkvariable */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkname (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mkname (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBname)) return (_currn);
if (IsSymb (_currn, SYMBvariable)) return (Mkrule_52(_coordref, _currn));
return(NULLNODEPTR);
}/* Mkname */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mktask_name (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR Mktask_name (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBtask_name)) return (_currn);
return(NULLNODEPTR);
}/* Mktask_name */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_1 (POSITION *_coordref)
#else
NODEPTR Mkrule_1 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_1 _currn;
#ifdef __cplusplus
_currn = new _TPrule_1;
#else
_currn = (_TPPrule_1) TreeNodeAlloc (sizeof (struct _TPrule_1));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_1;
_SETCOORD(_currn)
_TERMACT_rule_1;
return ( (NODEPTR) _currn);
}/* Mkrule_1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_2 (POSITION *_coordref)
#else
NODEPTR Mkrule_2 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_2 _currn;
#ifdef __cplusplus
_currn = new _TPrule_2;
#else
_currn = (_TPPrule_2) TreeNodeAlloc (sizeof (struct _TPrule_2));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_2;
_SETCOORD(_currn)
_TERMACT_rule_2;
return ( (NODEPTR) _currn);
}/* Mkrule_2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_3 (POSITION *_coordref)
#else
NODEPTR Mkrule_3 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_3 _currn;
#ifdef __cplusplus
_currn = new _TPrule_3;
#else
_currn = (_TPPrule_3) TreeNodeAlloc (sizeof (struct _TPrule_3));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_3;
_SETCOORD(_currn)
_TERMACT_rule_3;
return ( (NODEPTR) _currn);
}/* Mkrule_3 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_4 (POSITION *_coordref)
#else
NODEPTR Mkrule_4 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_4 _currn;
#ifdef __cplusplus
_currn = new _TPrule_4;
#else
_currn = (_TPPrule_4) TreeNodeAlloc (sizeof (struct _TPrule_4));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_4;
_SETCOORD(_currn)
_TERMACT_rule_4;
return ( (NODEPTR) _currn);
}/* Mkrule_4 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_5 (POSITION *_coordref)
#else
NODEPTR Mkrule_5 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_5 _currn;
#ifdef __cplusplus
_currn = new _TPrule_5;
#else
_currn = (_TPPrule_5) TreeNodeAlloc (sizeof (struct _TPrule_5));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_5;
_SETCOORD(_currn)
_TERMACT_rule_5;
return ( (NODEPTR) _currn);
}/* Mkrule_5 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_6 (POSITION *_coordref)
#else
NODEPTR Mkrule_6 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_6 _currn;
#ifdef __cplusplus
_currn = new _TPrule_6;
#else
_currn = (_TPPrule_6) TreeNodeAlloc (sizeof (struct _TPrule_6));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_6;
_SETCOORD(_currn)
_TERMACT_rule_6;
return ( (NODEPTR) _currn);
}/* Mkrule_6 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_7 (POSITION *_coordref)
#else
NODEPTR Mkrule_7 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_7 _currn;
#ifdef __cplusplus
_currn = new _TPrule_7;
#else
_currn = (_TPPrule_7) TreeNodeAlloc (sizeof (struct _TPrule_7));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_7;
_SETCOORD(_currn)
_TERMACT_rule_7;
return ( (NODEPTR) _currn);
}/* Mkrule_7 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_8 (POSITION *_coordref)
#else
NODEPTR Mkrule_8 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_8 _currn;
#ifdef __cplusplus
_currn = new _TPrule_8;
#else
_currn = (_TPPrule_8) TreeNodeAlloc (sizeof (struct _TPrule_8));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_8;
_SETCOORD(_currn)
_TERMACT_rule_8;
return ( (NODEPTR) _currn);
}/* Mkrule_8 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_9 (POSITION *_coordref)
#else
NODEPTR Mkrule_9 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_9 _currn;
#ifdef __cplusplus
_currn = new _TPrule_9;
#else
_currn = (_TPPrule_9) TreeNodeAlloc (sizeof (struct _TPrule_9));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_9;
_SETCOORD(_currn)
_TERMACT_rule_9;
return ( (NODEPTR) _currn);
}/* Mkrule_9 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_10 (POSITION *_coordref)
#else
NODEPTR Mkrule_10 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_10 _currn;
#ifdef __cplusplus
_currn = new _TPrule_10;
#else
_currn = (_TPPrule_10) TreeNodeAlloc (sizeof (struct _TPrule_10));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_10;
_SETCOORD(_currn)
_TERMACT_rule_10;
return ( (NODEPTR) _currn);
}/* Mkrule_10 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_11 (POSITION *_coordref)
#else
NODEPTR Mkrule_11 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_11 _currn;
#ifdef __cplusplus
_currn = new _TPrule_11;
#else
_currn = (_TPPrule_11) TreeNodeAlloc (sizeof (struct _TPrule_11));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_11;
_SETCOORD(_currn)
_TERMACT_rule_11;
return ( (NODEPTR) _currn);
}/* Mkrule_11 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_12 (POSITION *_coordref)
#else
NODEPTR Mkrule_12 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_12 _currn;
#ifdef __cplusplus
_currn = new _TPrule_12;
#else
_currn = (_TPPrule_12) TreeNodeAlloc (sizeof (struct _TPrule_12));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_12;
_SETCOORD(_currn)
_TERMACT_rule_12;
return ( (NODEPTR) _currn);
}/* Mkrule_12 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_13 (POSITION *_coordref)
#else
NODEPTR Mkrule_13 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_13 _currn;
#ifdef __cplusplus
_currn = new _TPrule_13;
#else
_currn = (_TPPrule_13) TreeNodeAlloc (sizeof (struct _TPrule_13));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_13;
_SETCOORD(_currn)
_TERMACT_rule_13;
return ( (NODEPTR) _currn);
}/* Mkrule_13 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_14 (POSITION *_coordref)
#else
NODEPTR Mkrule_14 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_14 _currn;
#ifdef __cplusplus
_currn = new _TPrule_14;
#else
_currn = (_TPPrule_14) TreeNodeAlloc (sizeof (struct _TPrule_14));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_14;
_SETCOORD(_currn)
_TERMACT_rule_14;
return ( (NODEPTR) _currn);
}/* Mkrule_14 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_15 (POSITION *_coordref)
#else
NODEPTR Mkrule_15 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_15 _currn;
#ifdef __cplusplus
_currn = new _TPrule_15;
#else
_currn = (_TPPrule_15) TreeNodeAlloc (sizeof (struct _TPrule_15));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_15;
_SETCOORD(_currn)
_TERMACT_rule_15;
return ( (NODEPTR) _currn);
}/* Mkrule_15 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_16 (POSITION *_coordref)
#else
NODEPTR Mkrule_16 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_16 _currn;
#ifdef __cplusplus
_currn = new _TPrule_16;
#else
_currn = (_TPPrule_16) TreeNodeAlloc (sizeof (struct _TPrule_16));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_16;
_SETCOORD(_currn)
_TERMACT_rule_16;
return ( (NODEPTR) _currn);
}/* Mkrule_16 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_17 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_17 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_17 _currn;
#ifdef __cplusplus
_currn = new _TPrule_17;
#else
_currn = (_TPPrule_17) TreeNodeAlloc (sizeof (struct _TPrule_17));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_17;
_currn->_desc1 = (_TSPfile) Mkfile (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 1 can not be made a file node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_17;
return ( (NODEPTR) _currn);
}/* Mkrule_17 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_18 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_18 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_18 _currn;
#ifdef __cplusplus
_currn = new _TPrule_18;
#else
_currn = (_TPPrule_18) TreeNodeAlloc (sizeof (struct _TPrule_18));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_18;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_18: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_18;
return ( (NODEPTR) _currn);
}/* Mkrule_18 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_19 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_19 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_19 _currn;
#ifdef __cplusplus
_currn = new _TPrule_19;
#else
_currn = (_TPPrule_19) TreeNodeAlloc (sizeof (struct _TPrule_19));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_19;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_19: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_19;
return ( (NODEPTR) _currn);
}/* Mkrule_19 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_20 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_20 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_20 _currn;
#ifdef __cplusplus
_currn = new _TPrule_20;
#else
_currn = (_TPPrule_20) TreeNodeAlloc (sizeof (struct _TPrule_20));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_20;
_currn->_desc1 = (_TSPfile) Mkfile (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_20: root of subtree no. 1 can not be made a file node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_20;
return ( (NODEPTR) _currn);
}/* Mkrule_20 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_21 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_21 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_21 _currn;
#ifdef __cplusplus
_currn = new _TPrule_21;
#else
_currn = (_TPPrule_21) TreeNodeAlloc (sizeof (struct _TPrule_21));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_21;
_SETCOORD(_currn)
_TERMACT_rule_21;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "file_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_21 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_22 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_22 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_22 _currn;
#ifdef __cplusplus
_currn = new _TPrule_22;
#else
_currn = (_TPPrule_22) TreeNodeAlloc (sizeof (struct _TPrule_22));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_22;
_currn->_desc1 = (_TSPdir) Mkdir (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_22: root of subtree no. 1 can not be made a dir node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_22;
return ( (NODEPTR) _currn);
}/* Mkrule_22 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_23 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_23 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_23 _currn;
#ifdef __cplusplus
_currn = new _TPrule_23;
#else
_currn = (_TPPrule_23) TreeNodeAlloc (sizeof (struct _TPrule_23));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_23;
_SETCOORD(_currn)
_TERMACT_rule_23;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "dir_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_23 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_24 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_24 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_24 _currn;
#ifdef __cplusplus
_currn = new _TPrule_24;
#else
_currn = (_TPPrule_24) TreeNodeAlloc (sizeof (struct _TPrule_24));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_24;
_currn->_desc1 = (_TSPnumber) Mknumber (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_24: root of subtree no. 1 can not be made a number node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_24;
return ( (NODEPTR) _currn);
}/* Mkrule_24 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_25 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_25 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_25 _currn;
#ifdef __cplusplus
_currn = new _TPrule_25;
#else
_currn = (_TPPrule_25) TreeNodeAlloc (sizeof (struct _TPrule_25));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_25;
_SETCOORD(_currn)
_TERMACT_rule_25;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "num_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_25 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_26 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_26 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_26 _currn;
#ifdef __cplusplus
_currn = new _TPrule_26;
#else
_currn = (_TPPrule_26) TreeNodeAlloc (sizeof (struct _TPrule_26));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_26;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_26: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_26: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_26;
return ( (NODEPTR) _currn);
}/* Mkrule_26 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_27 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_27 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_27 _currn;
#ifdef __cplusplus
_currn = new _TPrule_27;
#else
_currn = (_TPPrule_27) TreeNodeAlloc (sizeof (struct _TPrule_27));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_27;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_27: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_27: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_27;
return ( (NODEPTR) _currn);
}/* Mkrule_27 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_28 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_28 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_28 _currn;
#ifdef __cplusplus
_currn = new _TPrule_28;
#else
_currn = (_TPPrule_28) TreeNodeAlloc (sizeof (struct _TPrule_28));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_28;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_28: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_28: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_28;
return ( (NODEPTR) _currn);
}/* Mkrule_28 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_29 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_29 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_29 _currn;
#ifdef __cplusplus
_currn = new _TPrule_29;
#else
_currn = (_TPPrule_29) TreeNodeAlloc (sizeof (struct _TPrule_29));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_29;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_29: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_29: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_29;
return ( (NODEPTR) _currn);
}/* Mkrule_29 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_30 (POSITION *_coordref)
#else
NODEPTR Mkrule_30 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_30 _currn;
#ifdef __cplusplus
_currn = new _TPrule_30;
#else
_currn = (_TPPrule_30) TreeNodeAlloc (sizeof (struct _TPrule_30));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_30;
_SETCOORD(_currn)
_TERMACT_rule_30;
return ( (NODEPTR) _currn);
}/* Mkrule_30 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_31 (POSITION *_coordref)
#else
NODEPTR Mkrule_31 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_31 _currn;
#ifdef __cplusplus
_currn = new _TPrule_31;
#else
_currn = (_TPPrule_31) TreeNodeAlloc (sizeof (struct _TPrule_31));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_31;
_SETCOORD(_currn)
_TERMACT_rule_31;
return ( (NODEPTR) _currn);
}/* Mkrule_31 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_32 (POSITION *_coordref)
#else
NODEPTR Mkrule_32 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_32 _currn;
#ifdef __cplusplus
_currn = new _TPrule_32;
#else
_currn = (_TPPrule_32) TreeNodeAlloc (sizeof (struct _TPrule_32));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_32;
_SETCOORD(_currn)
_TERMACT_rule_32;
return ( (NODEPTR) _currn);
}/* Mkrule_32 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_33 (POSITION *_coordref)
#else
NODEPTR Mkrule_33 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_33 _currn;
#ifdef __cplusplus
_currn = new _TPrule_33;
#else
_currn = (_TPPrule_33) TreeNodeAlloc (sizeof (struct _TPrule_33));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_33;
_SETCOORD(_currn)
_TERMACT_rule_33;
return ( (NODEPTR) _currn);
}/* Mkrule_33 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_34 (POSITION *_coordref)
#else
NODEPTR Mkrule_34 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_34 _currn;
#ifdef __cplusplus
_currn = new _TPrule_34;
#else
_currn = (_TPPrule_34) TreeNodeAlloc (sizeof (struct _TPrule_34));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_34;
_SETCOORD(_currn)
_TERMACT_rule_34;
return ( (NODEPTR) _currn);
}/* Mkrule_34 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_35 (POSITION *_coordref)
#else
NODEPTR Mkrule_35 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_35 _currn;
#ifdef __cplusplus
_currn = new _TPrule_35;
#else
_currn = (_TPPrule_35) TreeNodeAlloc (sizeof (struct _TPrule_35));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_35;
_SETCOORD(_currn)
_TERMACT_rule_35;
return ( (NODEPTR) _currn);
}/* Mkrule_35 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_36 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_36 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_36 _currn;
#ifdef __cplusplus
_currn = new _TPrule_36;
#else
_currn = (_TPPrule_36) TreeNodeAlloc (sizeof (struct _TPrule_36));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_36;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_36: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_36;
return ( (NODEPTR) _currn);
}/* Mkrule_36 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_37 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_37 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_37 _currn;
#ifdef __cplusplus
_currn = new _TPrule_37;
#else
_currn = (_TPPrule_37) TreeNodeAlloc (sizeof (struct _TPrule_37));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_37;
_currn->_desc1 = (_TSPclass_name) Mkclass_name (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_37: root of subtree no. 1 can not be made a class_name node ", 0, _coordref);
_currn->_desc2 = (_TSPparam) Mkparam (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_37: root of subtree no. 2 can not be made a param node ", 0, _coordref);
_currn->_desc3 = (_TSPstatements) Mkstatements (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_37: root of subtree no. 3 can not be made a statements node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_37;
return ( (NODEPTR) _currn);
}/* Mkrule_37 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_38 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_38 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_38 _currn;
#ifdef __cplusplus
_currn = new _TPrule_38;
#else
_currn = (_TPPrule_38) TreeNodeAlloc (sizeof (struct _TPrule_38));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_38;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_38: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_38;
return ( (NODEPTR) _currn);
}/* Mkrule_38 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_39 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_39 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_39 _currn;
#ifdef __cplusplus
_currn = new _TPrule_39;
#else
_currn = (_TPPrule_39) TreeNodeAlloc (sizeof (struct _TPrule_39));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_39;
_currn->_desc1 = (_TSPclass_name) Mkclass_name (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_39: root of subtree no. 1 can not be made a class_name node ", 0, _coordref);
_currn->_desc2 = (_TSPparam) Mkparam (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_39: root of subtree no. 2 can not be made a param node ", 0, _coordref);
_currn->_desc3 = (_TSPstatements) Mkstatements (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_39: root of subtree no. 3 can not be made a statements node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_39;
return ( (NODEPTR) _currn);
}/* Mkrule_39 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_40 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_40 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_40 _currn;
#ifdef __cplusplus
_currn = new _TPrule_40;
#else
_currn = (_TPPrule_40) TreeNodeAlloc (sizeof (struct _TPrule_40));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_40;
_currn->_desc1 = (_TSPclass_name) Mkclass_name (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_40: root of subtree no. 1 can not be made a class_name node ", 0, _coordref);
_currn->_desc2 = (_TSPclass_name) Mkclass_name (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_40: root of subtree no. 2 can not be made a class_name node ", 0, _coordref);
_currn->_desc3 = (_TSPstatements) Mkstatements (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_40: root of subtree no. 3 can not be made a statements node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_40;
return ( (NODEPTR) _currn);
}/* Mkrule_40 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_41 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_41 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_41 _currn;
#ifdef __cplusplus
_currn = new _TPrule_41;
#else
_currn = (_TPPrule_41) TreeNodeAlloc (sizeof (struct _TPrule_41));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_41;
_currn->_desc1 = (_TSPclass_name) Mkclass_name (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_41: root of subtree no. 1 can not be made a class_name node ", 0, _coordref);
_currn->_desc2 = (_TSPstatements) Mkstatements (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_41: root of subtree no. 2 can not be made a statements node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_41;
return ( (NODEPTR) _currn);
}/* Mkrule_41 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_42 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_42 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_42 _currn;
#ifdef __cplusplus
_currn = new _TPrule_42;
#else
_currn = (_TPPrule_42) TreeNodeAlloc (sizeof (struct _TPrule_42));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_42;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_42: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_42: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_42;
return ( (NODEPTR) _currn);
}/* Mkrule_42 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_43 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_43 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_43 _currn;
#ifdef __cplusplus
_currn = new _TPrule_43;
#else
_currn = (_TPPrule_43) TreeNodeAlloc (sizeof (struct _TPrule_43));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_43;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_43: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_43: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_currn->_desc3 = (_TSPwords) Mkwords (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_43: root of subtree no. 3 can not be made a words node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_43;
return ( (NODEPTR) _currn);
}/* Mkrule_43 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_44 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_44 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_44 _currn;
#ifdef __cplusplus
_currn = new _TPrule_44;
#else
_currn = (_TPPrule_44) TreeNodeAlloc (sizeof (struct _TPrule_44));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_44;
_SETCOORD(_currn)
_TERMACT_rule_44;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "word_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_44 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_45 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_45 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_45 _currn;
#ifdef __cplusplus
_currn = new _TPrule_45;
#else
_currn = (_TPPrule_45) TreeNodeAlloc (sizeof (struct _TPrule_45));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_45;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_45: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_45: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_currn->_desc3 = (_TSPpairs) Mkpairs (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_45: root of subtree no. 3 can not be made a pairs node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_45;
return ( (NODEPTR) _currn);
}/* Mkrule_45 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_46 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_46 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_46 _currn;
#ifdef __cplusplus
_currn = new _TPrule_46;
#else
_currn = (_TPPrule_46) TreeNodeAlloc (sizeof (struct _TPrule_46));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_46;
_SETCOORD(_currn)
_TERMACT_rule_46;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "fill", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_46 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_47 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_47 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_47 _currn;
#ifdef __cplusplus
_currn = new _TPrule_47;
#else
_currn = (_TPPrule_47) TreeNodeAlloc (sizeof (struct _TPrule_47));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_47;
_currn->_desc1 = (_TSPextvar) Mkextvar (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_47: root of subtree no. 1 can not be made a extvar node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_47;
return ( (NODEPTR) _currn);
}/* Mkrule_47 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_48 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_48 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_48 _currn;
#ifdef __cplusplus
_currn = new _TPrule_48;
#else
_currn = (_TPPrule_48) TreeNodeAlloc (sizeof (struct _TPrule_48));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_48;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_48: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_48;
return ( (NODEPTR) _currn);
}/* Mkrule_48 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_49 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_49 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_49 _currn;
#ifdef __cplusplus
_currn = new _TPrule_49;
#else
_currn = (_TPPrule_49) TreeNodeAlloc (sizeof (struct _TPrule_49));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_49;
_currn->_desc1 = (_TSPwords) Mkwords (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_49: root of subtree no. 1 can not be made a words node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_49;
return ( (NODEPTR) _currn);
}/* Mkrule_49 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_50 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_50 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_50 _currn;
#ifdef __cplusplus
_currn = new _TPrule_50;
#else
_currn = (_TPPrule_50) TreeNodeAlloc (sizeof (struct _TPrule_50));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_50;
_SETCOORD(_currn)
_TERMACT_rule_50;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "dir_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_50 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_51 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_51 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_51 _currn;
#ifdef __cplusplus
_currn = new _TPrule_51;
#else
_currn = (_TPPrule_51) TreeNodeAlloc (sizeof (struct _TPrule_51));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_51;
_SETCOORD(_currn)
_TERMACT_rule_51;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "dir_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_51 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_52 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_52 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_52 _currn;
#ifdef __cplusplus
_currn = new _TPrule_52;
#else
_currn = (_TPPrule_52) TreeNodeAlloc (sizeof (struct _TPrule_52));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_52;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_52: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_52;
return ( (NODEPTR) _currn);
}/* Mkrule_52 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_53 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_53 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_53 _currn;
#ifdef __cplusplus
_currn = new _TPrule_53;
#else
_currn = (_TPPrule_53) TreeNodeAlloc (sizeof (struct _TPrule_53));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_53;
_SETCOORD(_currn)
_TERMACT_rule_53;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "word_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_53 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_54 (POSITION *_coordref, int _TERM1, NODEPTR _desc1, int _TERM2)
#else
NODEPTR Mkrule_54 (_coordref, _TERM1,_desc1, _TERM2)
	POSITION *_coordref;
	int _TERM1;
	NODEPTR _desc1;
	int _TERM2;
#endif
{	_TPPrule_54 _currn;
#ifdef __cplusplus
_currn = new _TPrule_54;
#else
_currn = (_TPPrule_54) TreeNodeAlloc (sizeof (struct _TPrule_54));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_54;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_54: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_54;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[1]", _TERM1);
#endif

#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[2]", _TERM2);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_54 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_55 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_55 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_55 _currn;
#ifdef __cplusplus
_currn = new _TPrule_55;
#else
_currn = (_TPPrule_55) TreeNodeAlloc (sizeof (struct _TPrule_55));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_55;
_SETCOORD(_currn)
_TERMACT_rule_55;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "file_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_55 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_56 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_56 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_56 _currn;
#ifdef __cplusplus
_currn = new _TPrule_56;
#else
_currn = (_TPPrule_56) TreeNodeAlloc (sizeof (struct _TPrule_56));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_56;
_SETCOORD(_currn)
_TERMACT_rule_56;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "file_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_56 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_57 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_57 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_57 _currn;
#ifdef __cplusplus
_currn = new _TPrule_57;
#else
_currn = (_TPPrule_57) TreeNodeAlloc (sizeof (struct _TPrule_57));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_57;
_SETCOORD(_currn)
_TERMACT_rule_57;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "word_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_57 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_58 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_58 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_58 _currn;
#ifdef __cplusplus
_currn = new _TPrule_58;
#else
_currn = (_TPPrule_58) TreeNodeAlloc (sizeof (struct _TPrule_58));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_58;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_58: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_58;
return ( (NODEPTR) _currn);
}/* Mkrule_58 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_59 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_59 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_59 _currn;
#ifdef __cplusplus
_currn = new _TPrule_59;
#else
_currn = (_TPPrule_59) TreeNodeAlloc (sizeof (struct _TPrule_59));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_59;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_59: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_59;
return ( (NODEPTR) _currn);
}/* Mkrule_59 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_60 (POSITION *_coordref)
#else
NODEPTR Mkrule_60 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_60 _currn;
#ifdef __cplusplus
_currn = new _TPrule_60;
#else
_currn = (_TPPrule_60) TreeNodeAlloc (sizeof (struct _TPrule_60));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_60;
_SETCOORD(_currn)
_TERMACT_rule_60;
return ( (NODEPTR) _currn);
}/* Mkrule_60 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_61 (POSITION *_coordref)
#else
NODEPTR Mkrule_61 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_61 _currn;
#ifdef __cplusplus
_currn = new _TPrule_61;
#else
_currn = (_TPPrule_61) TreeNodeAlloc (sizeof (struct _TPrule_61));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_61;
_SETCOORD(_currn)
_TERMACT_rule_61;
return ( (NODEPTR) _currn);
}/* Mkrule_61 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_62 (POSITION *_coordref)
#else
NODEPTR Mkrule_62 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_62 _currn;
#ifdef __cplusplus
_currn = new _TPrule_62;
#else
_currn = (_TPPrule_62) TreeNodeAlloc (sizeof (struct _TPrule_62));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_62;
_SETCOORD(_currn)
_TERMACT_rule_62;
return ( (NODEPTR) _currn);
}/* Mkrule_62 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_63 (POSITION *_coordref)
#else
NODEPTR Mkrule_63 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_63 _currn;
#ifdef __cplusplus
_currn = new _TPrule_63;
#else
_currn = (_TPPrule_63) TreeNodeAlloc (sizeof (struct _TPrule_63));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_63;
_SETCOORD(_currn)
_TERMACT_rule_63;
return ( (NODEPTR) _currn);
}/* Mkrule_63 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_64 (POSITION *_coordref)
#else
NODEPTR Mkrule_64 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_64 _currn;
#ifdef __cplusplus
_currn = new _TPrule_64;
#else
_currn = (_TPPrule_64) TreeNodeAlloc (sizeof (struct _TPrule_64));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_64;
_SETCOORD(_currn)
_TERMACT_rule_64;
return ( (NODEPTR) _currn);
}/* Mkrule_64 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_174 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_174 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_174 _currn;
#ifdef __cplusplus
_currn = new _TPrule_174;
#else
_currn = (_TPPrule_174) TreeNodeAlloc (sizeof (struct _TPrule_174));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_174;
_SETCOORD(_currn)
_TERMACT_rule_174;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "word_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_174 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_173 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_173 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_173 _currn;
#ifdef __cplusplus
_currn = new _TPrule_173;
#else
_currn = (_TPPrule_173) TreeNodeAlloc (sizeof (struct _TPrule_173));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_173;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_173: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_173: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_currn->_desc3 = (_TSPvariables) Mkvariables (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_173: root of subtree no. 3 can not be made a variables node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_173;
return ( (NODEPTR) _currn);
}/* Mkrule_173 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_172 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_172 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_172 _currn;
#ifdef __cplusplus
_currn = new _TPrule_172;
#else
_currn = (_TPPrule_172) TreeNodeAlloc (sizeof (struct _TPrule_172));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_172;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_172: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_172;
return ( (NODEPTR) _currn);
}/* Mkrule_172 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_171 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_171 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_171 _currn;
#ifdef __cplusplus
_currn = new _TPrule_171;
#else
_currn = (_TPPrule_171) TreeNodeAlloc (sizeof (struct _TPrule_171));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_171;
_currn->_desc1 = (_TSPword) Mkword (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_171: root of subtree no. 1 can not be made a word node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_171;
return ( (NODEPTR) _currn);
}/* Mkrule_171 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_170 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_170 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_170 _currn;
#ifdef __cplusplus
_currn = new _TPrule_170;
#else
_currn = (_TPPrule_170) TreeNodeAlloc (sizeof (struct _TPrule_170));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_170;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_170: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_170;
return ( (NODEPTR) _currn);
}/* Mkrule_170 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_169 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_169 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_169 _currn;
#ifdef __cplusplus
_currn = new _TPrule_169;
#else
_currn = (_TPPrule_169) TreeNodeAlloc (sizeof (struct _TPrule_169));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_169;
_currn->_desc1 = (_TSPtemplate) Mktemplate (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_169: root of subtree no. 1 can not be made a template node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_169;
return ( (NODEPTR) _currn);
}/* Mkrule_169 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_168 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_168 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_168 _currn;
#ifdef __cplusplus
_currn = new _TPrule_168;
#else
_currn = (_TPPrule_168) TreeNodeAlloc (sizeof (struct _TPrule_168));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_168;
_currn->_desc1 = (_TSPsources) Mksources (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_168: root of subtree no. 1 can not be made a sources node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_168;
return ( (NODEPTR) _currn);
}/* Mkrule_168 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_167 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_167 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_167 _currn;
#ifdef __cplusplus
_currn = new _TPrule_167;
#else
_currn = (_TPPrule_167) TreeNodeAlloc (sizeof (struct _TPrule_167));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_167;
_currn->_desc1 = (_TSPsource) Mksource (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_167: root of subtree no. 1 can not be made a source node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_167;
return ( (NODEPTR) _currn);
}/* Mkrule_167 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_166 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_166 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_166 _currn;
#ifdef __cplusplus
_currn = new _TPrule_166;
#else
_currn = (_TPPrule_166) TreeNodeAlloc (sizeof (struct _TPrule_166));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_166;
_currn->_desc1 = (_TSPset_or_get) Mkset_or_get (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_166: root of subtree no. 1 can not be made a set_or_get node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_166;
return ( (NODEPTR) _currn);
}/* Mkrule_166 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_165 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_165 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_165 _currn;
#ifdef __cplusplus
_currn = new _TPrule_165;
#else
_currn = (_TPPrule_165) TreeNodeAlloc (sizeof (struct _TPrule_165));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_165;
_currn->_desc1 = (_TSPreference) Mkreference (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_165: root of subtree no. 1 can not be made a reference node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_165;
return ( (NODEPTR) _currn);
}/* Mkrule_165 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_164 (POSITION *_coordref, int _TERM1, NODEPTR _desc1, int _TERM2)
#else
NODEPTR Mkrule_164 (_coordref, _TERM1,_desc1, _TERM2)
	POSITION *_coordref;
	int _TERM1;
	NODEPTR _desc1;
	int _TERM2;
#endif
{	_TPPrule_164 _currn;
#ifdef __cplusplus
_currn = new _TPrule_164;
#else
_currn = (_TPPrule_164) TreeNodeAlloc (sizeof (struct _TPrule_164));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_164;
_currn->_desc1 = (_TSPvalue) Mkvalue (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_164: root of subtree no. 1 can not be made a value node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_164;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[1]", _TERM1);
#endif

#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[2]", _TERM2);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_164 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_163 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_163 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_163 _currn;
#ifdef __cplusplus
_currn = new _TPrule_163;
#else
_currn = (_TPPrule_163) TreeNodeAlloc (sizeof (struct _TPrule_163));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_163;
_currn->_desc1 = (_TSPos) Mkos (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_163: root of subtree no. 1 can not be made a os node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_163;
return ( (NODEPTR) _currn);
}/* Mkrule_163 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_162 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_162 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_162 _currn;
#ifdef __cplusplus
_currn = new _TPrule_162;
#else
_currn = (_TPPrule_162) TreeNodeAlloc (sizeof (struct _TPrule_162));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_162;
_SETCOORD(_currn)
_TERMACT_rule_162;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "options", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_162 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_161 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_161 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_161 _currn;
#ifdef __cplusplus
_currn = new _TPrule_161;
#else
_currn = (_TPPrule_161) TreeNodeAlloc (sizeof (struct _TPrule_161));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_161;
_currn->_desc1 = (_TSPmetaparam) Mkmetaparam (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_161: root of subtree no. 1 can not be made a metaparam node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_161;
return ( (NODEPTR) _currn);
}/* Mkrule_161 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_160 (POSITION *_coordref)
#else
NODEPTR Mkrule_160 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_160 _currn;
#ifdef __cplusplus
_currn = new _TPrule_160;
#else
_currn = (_TPPrule_160) TreeNodeAlloc (sizeof (struct _TPrule_160));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_160;
_SETCOORD(_currn)
_TERMACT_rule_160;
return ( (NODEPTR) _currn);
}/* Mkrule_160 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_159 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_159 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_159 _currn;
#ifdef __cplusplus
_currn = new _TPrule_159;
#else
_currn = (_TPPrule_159) TreeNodeAlloc (sizeof (struct _TPrule_159));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_159;
_SETCOORD(_currn)
_TERMACT_rule_159;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "fill", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_159 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_158 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_158 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_158 _currn;
#ifdef __cplusplus
_currn = new _TPrule_158;
#else
_currn = (_TPPrule_158) TreeNodeAlloc (sizeof (struct _TPrule_158));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_158;
_currn->_desc1 = (_TSPextvar) Mkextvar (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_158: root of subtree no. 1 can not be made a extvar node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_158;
return ( (NODEPTR) _currn);
}/* Mkrule_158 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_157 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_157 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_157 _currn;
#ifdef __cplusplus
_currn = new _TPrule_157;
#else
_currn = (_TPPrule_157) TreeNodeAlloc (sizeof (struct _TPrule_157));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_157;
_currn->_desc1 = (_TSPboolean) Mkboolean (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_157: root of subtree no. 1 can not be made a boolean node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_157;
return ( (NODEPTR) _currn);
}/* Mkrule_157 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_156 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_156 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_156 _currn;
#ifdef __cplusplus
_currn = new _TPrule_156;
#else
_currn = (_TPPrule_156) TreeNodeAlloc (sizeof (struct _TPrule_156));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_156;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_156: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_156;
return ( (NODEPTR) _currn);
}/* Mkrule_156 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_155 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_155 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_155 _currn;
#ifdef __cplusplus
_currn = new _TPrule_155;
#else
_currn = (_TPPrule_155) TreeNodeAlloc (sizeof (struct _TPrule_155));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_155;
_currn->_desc1 = (_TSPtask_name) Mktask_name (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_155: root of subtree no. 1 can not be made a task_name node ", 0, _coordref);
_currn->_desc2 = (_TSPconfig) Mkconfig (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_155: root of subtree no. 2 can not be made a config node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_155;
return ( (NODEPTR) _currn);
}/* Mkrule_155 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_154 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_154 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_154 _currn;
#ifdef __cplusplus
_currn = new _TPrule_154;
#else
_currn = (_TPPrule_154) TreeNodeAlloc (sizeof (struct _TPrule_154));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_154;
_currn->_desc1 = (_TSPtask) Mktask (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_154: root of subtree no. 1 can not be made a task node ", 0, _coordref);
_currn->_desc2 = (_TSPtasks) Mktasks (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_154: root of subtree no. 2 can not be made a tasks node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_154;
return ( (NODEPTR) _currn);
}/* Mkrule_154 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_153 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_153 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_153 _currn;
#ifdef __cplusplus
_currn = new _TPrule_153;
#else
_currn = (_TPPrule_153) TreeNodeAlloc (sizeof (struct _TPrule_153));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_153;
_currn->_desc1 = (_TSPtask) Mktask (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_153: root of subtree no. 1 can not be made a task node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_153;
return ( (NODEPTR) _currn);
}/* Mkrule_153 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_152 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_152 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_152 _currn;
#ifdef __cplusplus
_currn = new _TPrule_152;
#else
_currn = (_TPPrule_152) TreeNodeAlloc (sizeof (struct _TPrule_152));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_152;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_152: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_152;
return ( (NODEPTR) _currn);
}/* Mkrule_152 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_151 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_151 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_151 _currn;
#ifdef __cplusplus
_currn = new _TPrule_151;
#else
_currn = (_TPPrule_151) TreeNodeAlloc (sizeof (struct _TPrule_151));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_151;
_currn->_desc1 = (_TSPtask) Mktask (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_151: root of subtree no. 1 can not be made a task node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_151;
return ( (NODEPTR) _currn);
}/* Mkrule_151 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_150 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_150 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_150 _currn;
#ifdef __cplusplus
_currn = new _TPrule_150;
#else
_currn = (_TPPrule_150) TreeNodeAlloc (sizeof (struct _TPrule_150));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_150;
_currn->_desc1 = (_TSPstatement) Mkstatement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_150: root of subtree no. 1 can not be made a statement node ", 0, _coordref);
_currn->_desc2 = (_TSPstatements) Mkstatements (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_150: root of subtree no. 2 can not be made a statements node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_150;
return ( (NODEPTR) _currn);
}/* Mkrule_150 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_149 (POSITION *_coordref)
#else
NODEPTR Mkrule_149 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_149 _currn;
#ifdef __cplusplus
_currn = new _TPrule_149;
#else
_currn = (_TPPrule_149) TreeNodeAlloc (sizeof (struct _TPrule_149));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_149;
_SETCOORD(_currn)
_TERMACT_rule_149;
return ( (NODEPTR) _currn);
}/* Mkrule_149 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_148 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_148 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_148 _currn;
#ifdef __cplusplus
_currn = new _TPrule_148;
#else
_currn = (_TPPrule_148) TreeNodeAlloc (sizeof (struct _TPrule_148));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_148;
_currn->_desc1 = (_TSPinclude) Mkinclude (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_148: root of subtree no. 1 can not be made a include node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_148;
return ( (NODEPTR) _currn);
}/* Mkrule_148 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_147 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_147 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_147 _currn;
#ifdef __cplusplus
_currn = new _TPrule_147;
#else
_currn = (_TPPrule_147) TreeNodeAlloc (sizeof (struct _TPrule_147));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_147;
_currn->_desc1 = (_TSPcondition) Mkcondition (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_147: root of subtree no. 1 can not be made a condition node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_147;
return ( (NODEPTR) _currn);
}/* Mkrule_147 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_146 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_146 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_146 _currn;
#ifdef __cplusplus
_currn = new _TPrule_146;
#else
_currn = (_TPPrule_146) TreeNodeAlloc (sizeof (struct _TPrule_146));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_146;
_currn->_desc1 = (_TSPclass) Mkclass (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_146: root of subtree no. 1 can not be made a class node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_146;
return ( (NODEPTR) _currn);
}/* Mkrule_146 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_145 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_145 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_145 _currn;
#ifdef __cplusplus
_currn = new _TPrule_145;
#else
_currn = (_TPPrule_145) TreeNodeAlloc (sizeof (struct _TPrule_145));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_145;
_currn->_desc1 = (_TSPattr_var) Mkattr_var (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_145: root of subtree no. 1 can not be made a attr_var node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_145;
return ( (NODEPTR) _currn);
}/* Mkrule_145 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_144 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_144 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_144 _currn;
#ifdef __cplusplus
_currn = new _TPrule_144;
#else
_currn = (_TPPrule_144) TreeNodeAlloc (sizeof (struct _TPrule_144));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_144;
_currn->_desc1 = (_TSPsource) Mksource (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_144: root of subtree no. 1 can not be made a source node ", 0, _coordref);
_currn->_desc2 = (_TSPsource) Mksource (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_144: root of subtree no. 2 can not be made a source node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_144;
return ( (NODEPTR) _currn);
}/* Mkrule_144 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_143 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_143 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_143 _currn;
#ifdef __cplusplus
_currn = new _TPrule_143;
#else
_currn = (_TPPrule_143) TreeNodeAlloc (sizeof (struct _TPrule_143));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_143;
_SETCOORD(_currn)
_TERMACT_rule_143;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "source_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_143 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_142 (POSITION *_coordref)
#else
NODEPTR Mkrule_142 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_142 _currn;
#ifdef __cplusplus
_currn = new _TPrule_142;
#else
_currn = (_TPPrule_142) TreeNodeAlloc (sizeof (struct _TPrule_142));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_142;
_SETCOORD(_currn)
_TERMACT_rule_142;
return ( (NODEPTR) _currn);
}/* Mkrule_142 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_141 (POSITION *_coordref)
#else
NODEPTR Mkrule_141 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_141 _currn;
#ifdef __cplusplus
_currn = new _TPrule_141;
#else
_currn = (_TPPrule_141) TreeNodeAlloc (sizeof (struct _TPrule_141));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_141;
_SETCOORD(_currn)
_TERMACT_rule_141;
return ( (NODEPTR) _currn);
}/* Mkrule_141 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_140 (POSITION *_coordref)
#else
NODEPTR Mkrule_140 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_140 _currn;
#ifdef __cplusplus
_currn = new _TPrule_140;
#else
_currn = (_TPPrule_140) TreeNodeAlloc (sizeof (struct _TPrule_140));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_140;
_SETCOORD(_currn)
_TERMACT_rule_140;
return ( (NODEPTR) _currn);
}/* Mkrule_140 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_139 (POSITION *_coordref)
#else
NODEPTR Mkrule_139 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_139 _currn;
#ifdef __cplusplus
_currn = new _TPrule_139;
#else
_currn = (_TPPrule_139) TreeNodeAlloc (sizeof (struct _TPrule_139));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_139;
_SETCOORD(_currn)
_TERMACT_rule_139;
return ( (NODEPTR) _currn);
}/* Mkrule_139 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_138 (POSITION *_coordref)
#else
NODEPTR Mkrule_138 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_138 _currn;
#ifdef __cplusplus
_currn = new _TPrule_138;
#else
_currn = (_TPPrule_138) TreeNodeAlloc (sizeof (struct _TPrule_138));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_138;
_SETCOORD(_currn)
_TERMACT_rule_138;
return ( (NODEPTR) _currn);
}/* Mkrule_138 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_137 (POSITION *_coordref)
#else
NODEPTR Mkrule_137 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_137 _currn;
#ifdef __cplusplus
_currn = new _TPrule_137;
#else
_currn = (_TPPrule_137) TreeNodeAlloc (sizeof (struct _TPrule_137));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_137;
_SETCOORD(_currn)
_TERMACT_rule_137;
return ( (NODEPTR) _currn);
}/* Mkrule_137 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_136 (POSITION *_coordref)
#else
NODEPTR Mkrule_136 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_136 _currn;
#ifdef __cplusplus
_currn = new _TPrule_136;
#else
_currn = (_TPPrule_136) TreeNodeAlloc (sizeof (struct _TPrule_136));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_136;
_SETCOORD(_currn)
_TERMACT_rule_136;
return ( (NODEPTR) _currn);
}/* Mkrule_136 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_135 (POSITION *_coordref)
#else
NODEPTR Mkrule_135 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_135 _currn;
#ifdef __cplusplus
_currn = new _TPrule_135;
#else
_currn = (_TPPrule_135) TreeNodeAlloc (sizeof (struct _TPrule_135));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_135;
_SETCOORD(_currn)
_TERMACT_rule_135;
return ( (NODEPTR) _currn);
}/* Mkrule_135 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_134 (POSITION *_coordref)
#else
NODEPTR Mkrule_134 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_134 _currn;
#ifdef __cplusplus
_currn = new _TPrule_134;
#else
_currn = (_TPPrule_134) TreeNodeAlloc (sizeof (struct _TPrule_134));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_134;
_SETCOORD(_currn)
_TERMACT_rule_134;
return ( (NODEPTR) _currn);
}/* Mkrule_134 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_133 (POSITION *_coordref)
#else
NODEPTR Mkrule_133 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_133 _currn;
#ifdef __cplusplus
_currn = new _TPrule_133;
#else
_currn = (_TPPrule_133) TreeNodeAlloc (sizeof (struct _TPrule_133));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_133;
_SETCOORD(_currn)
_TERMACT_rule_133;
return ( (NODEPTR) _currn);
}/* Mkrule_133 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_132 (POSITION *_coordref)
#else
NODEPTR Mkrule_132 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_132 _currn;
#ifdef __cplusplus
_currn = new _TPrule_132;
#else
_currn = (_TPPrule_132) TreeNodeAlloc (sizeof (struct _TPrule_132));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_132;
_SETCOORD(_currn)
_TERMACT_rule_132;
return ( (NODEPTR) _currn);
}/* Mkrule_132 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_131 (POSITION *_coordref)
#else
NODEPTR Mkrule_131 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_131 _currn;
#ifdef __cplusplus
_currn = new _TPrule_131;
#else
_currn = (_TPPrule_131) TreeNodeAlloc (sizeof (struct _TPrule_131));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_131;
_SETCOORD(_currn)
_TERMACT_rule_131;
return ( (NODEPTR) _currn);
}/* Mkrule_131 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_130 (POSITION *_coordref)
#else
NODEPTR Mkrule_130 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_130 _currn;
#ifdef __cplusplus
_currn = new _TPrule_130;
#else
_currn = (_TPPrule_130) TreeNodeAlloc (sizeof (struct _TPrule_130));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_130;
_SETCOORD(_currn)
_TERMACT_rule_130;
return ( (NODEPTR) _currn);
}/* Mkrule_130 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_129 (POSITION *_coordref)
#else
NODEPTR Mkrule_129 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_129 _currn;
#ifdef __cplusplus
_currn = new _TPrule_129;
#else
_currn = (_TPPrule_129) TreeNodeAlloc (sizeof (struct _TPrule_129));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_129;
_SETCOORD(_currn)
_TERMACT_rule_129;
return ( (NODEPTR) _currn);
}/* Mkrule_129 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_128 (POSITION *_coordref)
#else
NODEPTR Mkrule_128 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_128 _currn;
#ifdef __cplusplus
_currn = new _TPrule_128;
#else
_currn = (_TPPrule_128) TreeNodeAlloc (sizeof (struct _TPrule_128));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_128;
_SETCOORD(_currn)
_TERMACT_rule_128;
return ( (NODEPTR) _currn);
}/* Mkrule_128 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_127 (POSITION *_coordref)
#else
NODEPTR Mkrule_127 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_127 _currn;
#ifdef __cplusplus
_currn = new _TPrule_127;
#else
_currn = (_TPPrule_127) TreeNodeAlloc (sizeof (struct _TPrule_127));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_127;
_SETCOORD(_currn)
_TERMACT_rule_127;
return ( (NODEPTR) _currn);
}/* Mkrule_127 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_126 (POSITION *_coordref)
#else
NODEPTR Mkrule_126 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_126 _currn;
#ifdef __cplusplus
_currn = new _TPrule_126;
#else
_currn = (_TPPrule_126) TreeNodeAlloc (sizeof (struct _TPrule_126));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_126;
_SETCOORD(_currn)
_TERMACT_rule_126;
return ( (NODEPTR) _currn);
}/* Mkrule_126 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_125 (POSITION *_coordref)
#else
NODEPTR Mkrule_125 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_125 _currn;
#ifdef __cplusplus
_currn = new _TPrule_125;
#else
_currn = (_TPPrule_125) TreeNodeAlloc (sizeof (struct _TPrule_125));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_125;
_SETCOORD(_currn)
_TERMACT_rule_125;
return ( (NODEPTR) _currn);
}/* Mkrule_125 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_124 (POSITION *_coordref)
#else
NODEPTR Mkrule_124 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_124 _currn;
#ifdef __cplusplus
_currn = new _TPrule_124;
#else
_currn = (_TPPrule_124) TreeNodeAlloc (sizeof (struct _TPrule_124));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_124;
_SETCOORD(_currn)
_TERMACT_rule_124;
return ( (NODEPTR) _currn);
}/* Mkrule_124 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_123 (POSITION *_coordref)
#else
NODEPTR Mkrule_123 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_123 _currn;
#ifdef __cplusplus
_currn = new _TPrule_123;
#else
_currn = (_TPPrule_123) TreeNodeAlloc (sizeof (struct _TPrule_123));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_123;
_SETCOORD(_currn)
_TERMACT_rule_123;
return ( (NODEPTR) _currn);
}/* Mkrule_123 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_122 (POSITION *_coordref)
#else
NODEPTR Mkrule_122 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_122 _currn;
#ifdef __cplusplus
_currn = new _TPrule_122;
#else
_currn = (_TPPrule_122) TreeNodeAlloc (sizeof (struct _TPrule_122));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_122;
_SETCOORD(_currn)
_TERMACT_rule_122;
return ( (NODEPTR) _currn);
}/* Mkrule_122 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_121 (POSITION *_coordref)
#else
NODEPTR Mkrule_121 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_121 _currn;
#ifdef __cplusplus
_currn = new _TPrule_121;
#else
_currn = (_TPPrule_121) TreeNodeAlloc (sizeof (struct _TPrule_121));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_121;
_SETCOORD(_currn)
_TERMACT_rule_121;
return ( (NODEPTR) _currn);
}/* Mkrule_121 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_120 (POSITION *_coordref)
#else
NODEPTR Mkrule_120 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_120 _currn;
#ifdef __cplusplus
_currn = new _TPrule_120;
#else
_currn = (_TPPrule_120) TreeNodeAlloc (sizeof (struct _TPrule_120));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_120;
_SETCOORD(_currn)
_TERMACT_rule_120;
return ( (NODEPTR) _currn);
}/* Mkrule_120 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_119 (POSITION *_coordref)
#else
NODEPTR Mkrule_119 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_119 _currn;
#ifdef __cplusplus
_currn = new _TPrule_119;
#else
_currn = (_TPPrule_119) TreeNodeAlloc (sizeof (struct _TPrule_119));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_119;
_SETCOORD(_currn)
_TERMACT_rule_119;
return ( (NODEPTR) _currn);
}/* Mkrule_119 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_118 (POSITION *_coordref)
#else
NODEPTR Mkrule_118 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_118 _currn;
#ifdef __cplusplus
_currn = new _TPrule_118;
#else
_currn = (_TPPrule_118) TreeNodeAlloc (sizeof (struct _TPrule_118));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_118;
_SETCOORD(_currn)
_TERMACT_rule_118;
return ( (NODEPTR) _currn);
}/* Mkrule_118 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_117 (POSITION *_coordref)
#else
NODEPTR Mkrule_117 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_117 _currn;
#ifdef __cplusplus
_currn = new _TPrule_117;
#else
_currn = (_TPPrule_117) TreeNodeAlloc (sizeof (struct _TPrule_117));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_117;
_SETCOORD(_currn)
_TERMACT_rule_117;
return ( (NODEPTR) _currn);
}/* Mkrule_117 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_116 (POSITION *_coordref)
#else
NODEPTR Mkrule_116 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_116 _currn;
#ifdef __cplusplus
_currn = new _TPrule_116;
#else
_currn = (_TPPrule_116) TreeNodeAlloc (sizeof (struct _TPrule_116));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_116;
_SETCOORD(_currn)
_TERMACT_rule_116;
return ( (NODEPTR) _currn);
}/* Mkrule_116 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_115 (POSITION *_coordref)
#else
NODEPTR Mkrule_115 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_115 _currn;
#ifdef __cplusplus
_currn = new _TPrule_115;
#else
_currn = (_TPPrule_115) TreeNodeAlloc (sizeof (struct _TPrule_115));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_115;
_SETCOORD(_currn)
_TERMACT_rule_115;
return ( (NODEPTR) _currn);
}/* Mkrule_115 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_114 (POSITION *_coordref)
#else
NODEPTR Mkrule_114 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_114 _currn;
#ifdef __cplusplus
_currn = new _TPrule_114;
#else
_currn = (_TPPrule_114) TreeNodeAlloc (sizeof (struct _TPrule_114));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_114;
_SETCOORD(_currn)
_TERMACT_rule_114;
return ( (NODEPTR) _currn);
}/* Mkrule_114 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_113 (POSITION *_coordref)
#else
NODEPTR Mkrule_113 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_113 _currn;
#ifdef __cplusplus
_currn = new _TPrule_113;
#else
_currn = (_TPPrule_113) TreeNodeAlloc (sizeof (struct _TPrule_113));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_113;
_SETCOORD(_currn)
_TERMACT_rule_113;
return ( (NODEPTR) _currn);
}/* Mkrule_113 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_112 (POSITION *_coordref)
#else
NODEPTR Mkrule_112 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_112 _currn;
#ifdef __cplusplus
_currn = new _TPrule_112;
#else
_currn = (_TPPrule_112) TreeNodeAlloc (sizeof (struct _TPrule_112));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_112;
_SETCOORD(_currn)
_TERMACT_rule_112;
return ( (NODEPTR) _currn);
}/* Mkrule_112 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_111 (POSITION *_coordref)
#else
NODEPTR Mkrule_111 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_111 _currn;
#ifdef __cplusplus
_currn = new _TPrule_111;
#else
_currn = (_TPPrule_111) TreeNodeAlloc (sizeof (struct _TPrule_111));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_111;
_SETCOORD(_currn)
_TERMACT_rule_111;
return ( (NODEPTR) _currn);
}/* Mkrule_111 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_110 (POSITION *_coordref)
#else
NODEPTR Mkrule_110 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_110 _currn;
#ifdef __cplusplus
_currn = new _TPrule_110;
#else
_currn = (_TPPrule_110) TreeNodeAlloc (sizeof (struct _TPrule_110));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_110;
_SETCOORD(_currn)
_TERMACT_rule_110;
return ( (NODEPTR) _currn);
}/* Mkrule_110 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_109 (POSITION *_coordref)
#else
NODEPTR Mkrule_109 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_109 _currn;
#ifdef __cplusplus
_currn = new _TPrule_109;
#else
_currn = (_TPPrule_109) TreeNodeAlloc (sizeof (struct _TPrule_109));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_109;
_SETCOORD(_currn)
_TERMACT_rule_109;
return ( (NODEPTR) _currn);
}/* Mkrule_109 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_108 (POSITION *_coordref)
#else
NODEPTR Mkrule_108 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_108 _currn;
#ifdef __cplusplus
_currn = new _TPrule_108;
#else
_currn = (_TPPrule_108) TreeNodeAlloc (sizeof (struct _TPrule_108));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_108;
_SETCOORD(_currn)
_TERMACT_rule_108;
return ( (NODEPTR) _currn);
}/* Mkrule_108 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_107 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_107 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_107 _currn;
#ifdef __cplusplus
_currn = new _TPrule_107;
#else
_currn = (_TPPrule_107) TreeNodeAlloc (sizeof (struct _TPrule_107));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_107;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_107: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_107;
return ( (NODEPTR) _currn);
}/* Mkrule_107 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_106 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_106 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_106 _currn;
#ifdef __cplusplus
_currn = new _TPrule_106;
#else
_currn = (_TPPrule_106) TreeNodeAlloc (sizeof (struct _TPrule_106));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_106;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_106: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPcomparator) Mkcomparator (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_106: root of subtree no. 2 can not be made a comparator node ", 0, _coordref);
_currn->_desc3 = (_TSPvariable) Mkvariable (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_106: root of subtree no. 3 can not be made a variable node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_106;
return ( (NODEPTR) _currn);
}/* Mkrule_106 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_105 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_105 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_105 _currn;
#ifdef __cplusplus
_currn = new _TPrule_105;
#else
_currn = (_TPPrule_105) TreeNodeAlloc (sizeof (struct _TPrule_105));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_105;
_currn->_desc1 = (_TSPmetaparams) Mkmetaparams (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_105: root of subtree no. 1 can not be made a metaparams node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_105;
return ( (NODEPTR) _currn);
}/* Mkrule_105 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_104 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_104 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_104 _currn;
#ifdef __cplusplus
_currn = new _TPrule_104;
#else
_currn = (_TPPrule_104) TreeNodeAlloc (sizeof (struct _TPrule_104));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_104;
_currn->_desc1 = (_TSPG1) MkG1 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_104: root of subtree no. 1 can not be made a G1 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_104;
return ( (NODEPTR) _currn);
}/* Mkrule_104 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_103 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_103 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_103 _currn;
#ifdef __cplusplus
_currn = new _TPrule_103;
#else
_currn = (_TPPrule_103) TreeNodeAlloc (sizeof (struct _TPrule_103));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_103;
_currn->_desc1 = (_TSPvariables) Mkvariables (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_103: root of subtree no. 1 can not be made a variables node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_103;
return ( (NODEPTR) _currn);
}/* Mkrule_103 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_102 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_102 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_102 _currn;
#ifdef __cplusplus
_currn = new _TPrule_102;
#else
_currn = (_TPPrule_102) TreeNodeAlloc (sizeof (struct _TPrule_102));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_102;
_currn->_desc1 = (_TSPattrs) Mkattrs (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_102: root of subtree no. 1 can not be made a attrs node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_102;
return ( (NODEPTR) _currn);
}/* Mkrule_102 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_101 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_101 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_101 _currn;
#ifdef __cplusplus
_currn = new _TPrule_101;
#else
_currn = (_TPPrule_101) TreeNodeAlloc (sizeof (struct _TPrule_101));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_101;
_currn->_desc1 = (_TSPpair) Mkpair (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_101: root of subtree no. 1 can not be made a pair node ", 0, _coordref);
_currn->_desc2 = (_TSPpairs) Mkpairs (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_101: root of subtree no. 2 can not be made a pairs node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_101;
return ( (NODEPTR) _currn);
}/* Mkrule_101 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_100 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_100 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_100 _currn;
#ifdef __cplusplus
_currn = new _TPrule_100;
#else
_currn = (_TPPrule_100) TreeNodeAlloc (sizeof (struct _TPrule_100));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_100;
_currn->_desc1 = (_TSPpair) Mkpair (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_100: root of subtree no. 1 can not be made a pair node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_100;
return ( (NODEPTR) _currn);
}/* Mkrule_100 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_99 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_99 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_99 _currn;
#ifdef __cplusplus
_currn = new _TPrule_99;
#else
_currn = (_TPPrule_99) TreeNodeAlloc (sizeof (struct _TPrule_99));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_99;
_currn->_desc1 = (_TSPsetting) Mksetting (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_99: root of subtree no. 1 can not be made a setting node ", 0, _coordref);
_currn->_desc2 = (_TSPvalue) Mkvalue (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_99: root of subtree no. 2 can not be made a value node ", 0, _coordref);
_currn->_desc3 = (_TSPcomma) Mkcomma (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_99: root of subtree no. 3 can not be made a comma node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_99;
return ( (NODEPTR) _currn);
}/* Mkrule_99 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_98 (POSITION *_coordref)
#else
NODEPTR Mkrule_98 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_98 _currn;
#ifdef __cplusplus
_currn = new _TPrule_98;
#else
_currn = (_TPPrule_98) TreeNodeAlloc (sizeof (struct _TPrule_98));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_98;
_SETCOORD(_currn)
_TERMACT_rule_98;
return ( (NODEPTR) _currn);
}/* Mkrule_98 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_97 (POSITION *_coordref)
#else
NODEPTR Mkrule_97 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_97 _currn;
#ifdef __cplusplus
_currn = new _TPrule_97;
#else
_currn = (_TPPrule_97) TreeNodeAlloc (sizeof (struct _TPrule_97));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_97;
_SETCOORD(_currn)
_TERMACT_rule_97;
return ( (NODEPTR) _currn);
}/* Mkrule_97 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_96 (POSITION *_coordref)
#else
NODEPTR Mkrule_96 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_96 _currn;
#ifdef __cplusplus
_currn = new _TPrule_96;
#else
_currn = (_TPPrule_96) TreeNodeAlloc (sizeof (struct _TPrule_96));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_96;
_SETCOORD(_currn)
_TERMACT_rule_96;
return ( (NODEPTR) _currn);
}/* Mkrule_96 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_95 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_95 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_95 _currn;
#ifdef __cplusplus
_currn = new _TPrule_95;
#else
_currn = (_TPPrule_95) TreeNodeAlloc (sizeof (struct _TPrule_95));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_95;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_95: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPpairs) Mkpairs (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_95: root of subtree no. 2 can not be made a pairs node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_95;
return ( (NODEPTR) _currn);
}/* Mkrule_95 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_94 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_94 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_94 _currn;
#ifdef __cplusplus
_currn = new _TPrule_94;
#else
_currn = (_TPPrule_94) TreeNodeAlloc (sizeof (struct _TPrule_94));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_94;
_currn->_desc1 = (_TSPmetaparam) Mkmetaparam (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_94: root of subtree no. 1 can not be made a metaparam node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_94: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_currn->_desc3 = (_TSPmetaparams) Mkmetaparams (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_94: root of subtree no. 3 can not be made a metaparams node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_94;
return ( (NODEPTR) _currn);
}/* Mkrule_94 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_93 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_93 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_93 _currn;
#ifdef __cplusplus
_currn = new _TPrule_93;
#else
_currn = (_TPPrule_93) TreeNodeAlloc (sizeof (struct _TPrule_93));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_93;
_currn->_desc1 = (_TSPmetaparam) Mkmetaparam (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_93: root of subtree no. 1 can not be made a metaparam node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_93;
return ( (NODEPTR) _currn);
}/* Mkrule_93 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_92 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_92 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_92 _currn;
#ifdef __cplusplus
_currn = new _TPrule_92;
#else
_currn = (_TPPrule_92) TreeNodeAlloc (sizeof (struct _TPrule_92));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_92;
_currn->_desc1 = (_TSPvalue) Mkvalue (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_92: root of subtree no. 1 can not be made a value node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_92;
return ( (NODEPTR) _currn);
}/* Mkrule_92 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_91 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_91 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_91 _currn;
#ifdef __cplusplus
_currn = new _TPrule_91;
#else
_currn = (_TPPrule_91) TreeNodeAlloc (sizeof (struct _TPrule_91));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_91;
_currn->_desc1 = (_TSPvalue) Mkvalue (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_91: root of subtree no. 1 can not be made a value node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_91;
return ( (NODEPTR) _currn);
}/* Mkrule_91 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_90 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_90 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_90 _currn;
#ifdef __cplusplus
_currn = new _TPrule_90;
#else
_currn = (_TPPrule_90) TreeNodeAlloc (sizeof (struct _TPrule_90));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_90;
_currn->_desc1 = (_TSPvalue) Mkvalue (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_90: root of subtree no. 1 can not be made a value node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_90;
return ( (NODEPTR) _currn);
}/* Mkrule_90 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_89 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_89 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_89 _currn;
#ifdef __cplusplus
_currn = new _TPrule_89;
#else
_currn = (_TPPrule_89) TreeNodeAlloc (sizeof (struct _TPrule_89));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_89;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_89: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_89;
return ( (NODEPTR) _currn);
}/* Mkrule_89 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_88 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_88 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_88 _currn;
#ifdef __cplusplus
_currn = new _TPrule_88;
#else
_currn = (_TPPrule_88) TreeNodeAlloc (sizeof (struct _TPrule_88));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_88;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_88: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_currn->_desc2 = (_TSPvariable) Mkvariable (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_88: root of subtree no. 2 can not be made a variable node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_88;
return ( (NODEPTR) _currn);
}/* Mkrule_88 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_87 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_87 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_87 _currn;
#ifdef __cplusplus
_currn = new _TPrule_87;
#else
_currn = (_TPPrule_87) TreeNodeAlloc (sizeof (struct _TPrule_87));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_87;
_currn->_desc1 = (_TSPG1) MkG1 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_87: root of subtree no. 1 can not be made a G1 node ", 0, _coordref);
_currn->_desc2 = (_TSPclass) Mkclass (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_87: root of subtree no. 2 can not be made a class node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_87;
return ( (NODEPTR) _currn);
}/* Mkrule_87 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_86 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_86 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_86 _currn;
#ifdef __cplusplus
_currn = new _TPrule_86;
#else
_currn = (_TPPrule_86) TreeNodeAlloc (sizeof (struct _TPrule_86));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_86;
_currn->_desc1 = (_TSPclass) Mkclass (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_86: root of subtree no. 1 can not be made a class node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_86;
return ( (NODEPTR) _currn);
}/* Mkrule_86 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_85 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_85 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_85 _currn;
#ifdef __cplusplus
_currn = new _TPrule_85;
#else
_currn = (_TPPrule_85) TreeNodeAlloc (sizeof (struct _TPrule_85));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_85;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_85: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_currn->_desc2 = (_TSPname) Mkname (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_85: root of subtree no. 2 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_85;
return ( (NODEPTR) _currn);
}/* Mkrule_85 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_84 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_84 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_84 _currn;
#ifdef __cplusplus
_currn = new _TPrule_84;
#else
_currn = (_TPPrule_84) TreeNodeAlloc (sizeof (struct _TPrule_84));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_84;
_currn->_desc1 = (_TSPname) Mkname (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_84: root of subtree no. 1 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_84;
return ( (NODEPTR) _currn);
}/* Mkrule_84 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_83 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_83 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_83 _currn;
#ifdef __cplusplus
_currn = new _TPrule_83;
#else
_currn = (_TPPrule_83) TreeNodeAlloc (sizeof (struct _TPrule_83));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_83;
_currn->_desc1 = (_TSPpairs) Mkpairs (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_83: root of subtree no. 1 can not be made a pairs node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_83;
return ( (NODEPTR) _currn);
}/* Mkrule_83 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_82 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_82 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_82 _currn;
#ifdef __cplusplus
_currn = new _TPrule_82;
#else
_currn = (_TPPrule_82) TreeNodeAlloc (sizeof (struct _TPrule_82));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_82;
_currn->_desc1 = (_TSPcode) Mkcode (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_82: root of subtree no. 1 can not be made a code node ", 0, _coordref);
_currn->_desc2 = (_TSPtasks) Mktasks (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_82: root of subtree no. 2 can not be made a tasks node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_82;
return ( (NODEPTR) _currn);
}/* Mkrule_82 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_81 (POSITION *_coordref)
#else
NODEPTR Mkrule_81 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_81 _currn;
#ifdef __cplusplus
_currn = new _TPrule_81;
#else
_currn = (_TPPrule_81) TreeNodeAlloc (sizeof (struct _TPrule_81));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_81;
_SETCOORD(_currn)
_TERMACT_rule_81;
return ( (NODEPTR) _currn);
}/* Mkrule_81 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_80 (POSITION *_coordref)
#else
NODEPTR Mkrule_80 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_80 _currn;
#ifdef __cplusplus
_currn = new _TPrule_80;
#else
_currn = (_TPPrule_80) TreeNodeAlloc (sizeof (struct _TPrule_80));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_80;
_SETCOORD(_currn)
_TERMACT_rule_80;
return ( (NODEPTR) _currn);
}/* Mkrule_80 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_79 (POSITION *_coordref)
#else
NODEPTR Mkrule_79 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_79 _currn;
#ifdef __cplusplus
_currn = new _TPrule_79;
#else
_currn = (_TPPrule_79) TreeNodeAlloc (sizeof (struct _TPrule_79));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_79;
_SETCOORD(_currn)
_TERMACT_rule_79;
return ( (NODEPTR) _currn);
}/* Mkrule_79 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_78 (POSITION *_coordref)
#else
NODEPTR Mkrule_78 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_78 _currn;
#ifdef __cplusplus
_currn = new _TPrule_78;
#else
_currn = (_TPPrule_78) TreeNodeAlloc (sizeof (struct _TPrule_78));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_78;
_SETCOORD(_currn)
_TERMACT_rule_78;
return ( (NODEPTR) _currn);
}/* Mkrule_78 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_77 (POSITION *_coordref)
#else
NODEPTR Mkrule_77 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_77 _currn;
#ifdef __cplusplus
_currn = new _TPrule_77;
#else
_currn = (_TPPrule_77) TreeNodeAlloc (sizeof (struct _TPrule_77));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_77;
_SETCOORD(_currn)
_TERMACT_rule_77;
return ( (NODEPTR) _currn);
}/* Mkrule_77 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_76 (POSITION *_coordref)
#else
NODEPTR Mkrule_76 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_76 _currn;
#ifdef __cplusplus
_currn = new _TPrule_76;
#else
_currn = (_TPPrule_76) TreeNodeAlloc (sizeof (struct _TPrule_76));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_76;
_SETCOORD(_currn)
_TERMACT_rule_76;
return ( (NODEPTR) _currn);
}/* Mkrule_76 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_75 (POSITION *_coordref)
#else
NODEPTR Mkrule_75 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_75 _currn;
#ifdef __cplusplus
_currn = new _TPrule_75;
#else
_currn = (_TPPrule_75) TreeNodeAlloc (sizeof (struct _TPrule_75));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_75;
_SETCOORD(_currn)
_TERMACT_rule_75;
return ( (NODEPTR) _currn);
}/* Mkrule_75 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_74 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3, int _TERM2)
#else
NODEPTR Mkrule_74 (_coordref,_desc1,_desc2, _TERM1,_desc3, _TERM2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	int _TERM1;
	NODEPTR _desc3;
	int _TERM2;
#endif
{	_TPPrule_74 _currn;
#ifdef __cplusplus
_currn = new _TPrule_74;
#else
_currn = (_TPPrule_74) TreeNodeAlloc (sizeof (struct _TPrule_74));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_74;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_74: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPcomparator) Mkcomparator (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_74: root of subtree no. 2 can not be made a comparator node ", 0, _coordref);
_currn->_desc3 = (_TSPword) Mkword (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_74: root of subtree no. 3 can not be made a word node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_74;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[1]", _TERM1);
#endif

#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[2]", _TERM2);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_74 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_73 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3, int _TERM2)
#else
NODEPTR Mkrule_73 (_coordref,_desc1,_desc2, _TERM1,_desc3, _TERM2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	int _TERM1;
	NODEPTR _desc3;
	int _TERM2;
#endif
{	_TPPrule_73 _currn;
#ifdef __cplusplus
_currn = new _TPrule_73;
#else
_currn = (_TPPrule_73) TreeNodeAlloc (sizeof (struct _TPrule_73));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_73;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_73: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPcomparator) Mkcomparator (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_73: root of subtree no. 2 can not be made a comparator node ", 0, _coordref);
_currn->_desc3 = (_TSPnumber) Mknumber (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_73: root of subtree no. 3 can not be made a number node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_73;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[1]", _TERM1);
#endif

#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "plica[2]", _TERM2);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_73 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_72 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_72 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_72 _currn;
#ifdef __cplusplus
_currn = new _TPrule_72;
#else
_currn = (_TPPrule_72) TreeNodeAlloc (sizeof (struct _TPrule_72));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_72;
_currn->_desc1 = (_TSPmetaparam) Mkmetaparam (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_72: root of subtree no. 1 can not be made a metaparam node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_72;
return ( (NODEPTR) _currn);
}/* Mkrule_72 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_71 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_71 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_71 _currn;
#ifdef __cplusplus
_currn = new _TPrule_71;
#else
_currn = (_TPPrule_71) TreeNodeAlloc (sizeof (struct _TPrule_71));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_71;
_SETCOORD(_currn)
_TERMACT_rule_71;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "word_ident", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_71 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_70 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_70 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_70 _currn;
#ifdef __cplusplus
_currn = new _TPrule_70;
#else
_currn = (_TPPrule_70) TreeNodeAlloc (sizeof (struct _TPrule_70));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_70;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_70: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPword) Mkword (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_70: root of subtree no. 2 can not be made a word node ", 0, _coordref);
_currn->_desc3 = (_TSPvalue) Mkvalue (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_70: root of subtree no. 3 can not be made a value node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_70;
return ( (NODEPTR) _currn);
}/* Mkrule_70 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_69 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_69 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_69 _currn;
#ifdef __cplusplus
_currn = new _TPrule_69;
#else
_currn = (_TPPrule_69) TreeNodeAlloc (sizeof (struct _TPrule_69));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_69;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_69: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPos) Mkos (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_69: root of subtree no. 2 can not be made a os node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_69;
return ( (NODEPTR) _currn);
}/* Mkrule_69 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_68 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_68 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_68 _currn;
#ifdef __cplusplus
_currn = new _TPrule_68;
#else
_currn = (_TPPrule_68) TreeNodeAlloc (sizeof (struct _TPrule_68));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_68;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_68: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPnumber) Mknumber (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_68: root of subtree no. 2 can not be made a number node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_68;
return ( (NODEPTR) _currn);
}/* Mkrule_68 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_67 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_67 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_67 _currn;
#ifdef __cplusplus
_currn = new _TPrule_67;
#else
_currn = (_TPPrule_67) TreeNodeAlloc (sizeof (struct _TPrule_67));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_67;
_currn->_desc1 = (_TSPvariable) Mkvariable (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_67: root of subtree no. 1 can not be made a variable node ", 0, _coordref);
_currn->_desc2 = (_TSPname) Mkname (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_67: root of subtree no. 2 can not be made a name node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_67;
return ( (NODEPTR) _currn);
}/* Mkrule_67 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_66 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_66 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_66 _currn;
#ifdef __cplusplus
_currn = new _TPrule_66;
#else
_currn = (_TPPrule_66) TreeNodeAlloc (sizeof (struct _TPrule_66));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_66;
_currn->_desc1 = (_TSPattr_var) Mkattr_var (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_66: root of subtree no. 1 can not be made a attr_var node ", 0, _coordref);
_currn->_desc2 = (_TSPcomma) Mkcomma (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_66: root of subtree no. 2 can not be made a comma node ", 0, _coordref);
_currn->_desc3 = (_TSPattrs) Mkattrs (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_66: root of subtree no. 3 can not be made a attrs node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_66;
return ( (NODEPTR) _currn);
}/* Mkrule_66 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_65 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_65 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_65 _currn;
#ifdef __cplusplus
_currn = new _TPrule_65;
#else
_currn = (_TPPrule_65) TreeNodeAlloc (sizeof (struct _TPrule_65));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_65;
_currn->_desc1 = (_TSPattr_var) Mkattr_var (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_65: root of subtree no. 1 can not be made a attr_var node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_65;
return ( (NODEPTR) _currn);
}/* Mkrule_65 */
