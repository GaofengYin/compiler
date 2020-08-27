
/* definition of tree node structure */

#ifndef NODE_H
#define NODE_H
#include "err.h"
#include "nodeptr.h" /* defines NODEPTR */
#include "HEAD.h"

#ifdef MONITOR
#define _NODECOMMON int _prod; POSITION _coord; int _uid;
#else
#define _NODECOMMON int _prod;
#endif
struct NODEPTR_struct {
        _NODECOMMON
#ifdef __cplusplus
        void* operator new(size_t size);
#endif
};

typedef struct _TStemplate* _TSPtemplate;
typedef struct _TStask* _TSPtask;
typedef struct _TSstatement* _TSPstatement;
typedef struct _TSsources* _TSPsources;
typedef struct _TSsource* _TSPsource;
typedef struct _TSset_or_get* _TSPset_or_get;
typedef struct _TSreference* _TSPreference;
typedef struct _TSProgram* _TSPProgram;
typedef struct _TSvariables* _TSPvariables;
typedef struct _TSmetaparams* _TSPmetaparams;
typedef struct _TSG2* _TSPG2;
typedef struct _TSG1* _TSPG1;
typedef struct _TStasks* _TSPtasks;
typedef struct _TScondition* _TSPcondition;
typedef struct _TScomparator* _TSPcomparator;
typedef struct _TScode* _TSPcode;
typedef struct _TSos* _TSPos;
typedef struct _TSattr_var* _TSPattr_var;
typedef struct _TSattrs* _TSPattrs;
typedef struct _TSboolean* _TSPboolean;
typedef struct _TSmetaparam* _TSPmetaparam;
typedef struct _TSfile* _TSPfile;
typedef struct _TSdir* _TSPdir;
typedef struct _TSvalue* _TSPvalue;
typedef struct _TSnumber* _TSPnumber;
typedef struct _TSpair* _TSPpair;
typedef struct _TSsetting* _TSPsetting;
typedef struct _TSinclude* _TSPinclude;
typedef struct _TSparam* _TSPparam;
typedef struct _TSstatements* _TSPstatements;
typedef struct _TSclass_name* _TSPclass_name;
typedef struct _TSclass* _TSPclass;
typedef struct _TSword* _TSPword;
typedef struct _TSpairs* _TSPpairs;
typedef struct _TScomma* _TSPcomma;
typedef struct _TSconfig* _TSPconfig;
typedef struct _TSextvar* _TSPextvar;
typedef struct _TSwords* _TSPwords;
typedef struct _TSvariable* _TSPvariable;
typedef struct _TSname* _TSPname;
typedef struct _TStask_name* _TSPtask_name;
typedef struct _TPrule_1* _TPPrule_1;
typedef struct _TPrule_2* _TPPrule_2;
typedef struct _TPrule_3* _TPPrule_3;
typedef struct _TPrule_4* _TPPrule_4;
typedef struct _TPrule_5* _TPPrule_5;
typedef struct _TPrule_6* _TPPrule_6;
typedef struct _TPrule_7* _TPPrule_7;
typedef struct _TPrule_8* _TPPrule_8;
typedef struct _TPrule_9* _TPPrule_9;
typedef struct _TPrule_10* _TPPrule_10;
typedef struct _TPrule_11* _TPPrule_11;
typedef struct _TPrule_12* _TPPrule_12;
typedef struct _TPrule_13* _TPPrule_13;
typedef struct _TPrule_14* _TPPrule_14;
typedef struct _TPrule_15* _TPPrule_15;
typedef struct _TPrule_16* _TPPrule_16;
typedef struct _TPrule_17* _TPPrule_17;
typedef struct _TPrule_18* _TPPrule_18;
typedef struct _TPrule_19* _TPPrule_19;
typedef struct _TPrule_20* _TPPrule_20;
typedef struct _TPrule_21* _TPPrule_21;
typedef struct _TPrule_22* _TPPrule_22;
typedef struct _TPrule_23* _TPPrule_23;
typedef struct _TPrule_24* _TPPrule_24;
typedef struct _TPrule_25* _TPPrule_25;
typedef struct _TPrule_26* _TPPrule_26;
typedef struct _TPrule_27* _TPPrule_27;
typedef struct _TPrule_28* _TPPrule_28;
typedef struct _TPrule_29* _TPPrule_29;
typedef struct _TPrule_30* _TPPrule_30;
typedef struct _TPrule_31* _TPPrule_31;
typedef struct _TPrule_32* _TPPrule_32;
typedef struct _TPrule_33* _TPPrule_33;
typedef struct _TPrule_34* _TPPrule_34;
typedef struct _TPrule_35* _TPPrule_35;
typedef struct _TPrule_36* _TPPrule_36;
typedef struct _TPrule_37* _TPPrule_37;
typedef struct _TPrule_38* _TPPrule_38;
typedef struct _TPrule_39* _TPPrule_39;
typedef struct _TPrule_40* _TPPrule_40;
typedef struct _TPrule_41* _TPPrule_41;
typedef struct _TPrule_42* _TPPrule_42;
typedef struct _TPrule_43* _TPPrule_43;
typedef struct _TPrule_44* _TPPrule_44;
typedef struct _TPrule_45* _TPPrule_45;
typedef struct _TPrule_46* _TPPrule_46;
typedef struct _TPrule_47* _TPPrule_47;
typedef struct _TPrule_48* _TPPrule_48;
typedef struct _TPrule_49* _TPPrule_49;
typedef struct _TPrule_50* _TPPrule_50;
typedef struct _TPrule_51* _TPPrule_51;
typedef struct _TPrule_52* _TPPrule_52;
typedef struct _TPrule_53* _TPPrule_53;
typedef struct _TPrule_54* _TPPrule_54;
typedef struct _TPrule_55* _TPPrule_55;
typedef struct _TPrule_56* _TPPrule_56;
typedef struct _TPrule_57* _TPPrule_57;
typedef struct _TPrule_58* _TPPrule_58;
typedef struct _TPrule_59* _TPPrule_59;
typedef struct _TPrule_60* _TPPrule_60;
typedef struct _TPrule_61* _TPPrule_61;
typedef struct _TPrule_62* _TPPrule_62;
typedef struct _TPrule_63* _TPPrule_63;
typedef struct _TPrule_64* _TPPrule_64;
typedef struct _TPrule_174* _TPPrule_174;
typedef struct _TPrule_173* _TPPrule_173;
typedef struct _TPrule_172* _TPPrule_172;
typedef struct _TPrule_171* _TPPrule_171;
typedef struct _TPrule_170* _TPPrule_170;
typedef struct _TPrule_169* _TPPrule_169;
typedef struct _TPrule_168* _TPPrule_168;
typedef struct _TPrule_167* _TPPrule_167;
typedef struct _TPrule_166* _TPPrule_166;
typedef struct _TPrule_165* _TPPrule_165;
typedef struct _TPrule_164* _TPPrule_164;
typedef struct _TPrule_163* _TPPrule_163;
typedef struct _TPrule_162* _TPPrule_162;
typedef struct _TPrule_161* _TPPrule_161;
typedef struct _TPrule_160* _TPPrule_160;
typedef struct _TPrule_159* _TPPrule_159;
typedef struct _TPrule_158* _TPPrule_158;
typedef struct _TPrule_157* _TPPrule_157;
typedef struct _TPrule_156* _TPPrule_156;
typedef struct _TPrule_155* _TPPrule_155;
typedef struct _TPrule_154* _TPPrule_154;
typedef struct _TPrule_153* _TPPrule_153;
typedef struct _TPrule_152* _TPPrule_152;
typedef struct _TPrule_151* _TPPrule_151;
typedef struct _TPrule_150* _TPPrule_150;
typedef struct _TPrule_149* _TPPrule_149;
typedef struct _TPrule_148* _TPPrule_148;
typedef struct _TPrule_147* _TPPrule_147;
typedef struct _TPrule_146* _TPPrule_146;
typedef struct _TPrule_145* _TPPrule_145;
typedef struct _TPrule_144* _TPPrule_144;
typedef struct _TPrule_143* _TPPrule_143;
typedef struct _TPrule_142* _TPPrule_142;
typedef struct _TPrule_141* _TPPrule_141;
typedef struct _TPrule_140* _TPPrule_140;
typedef struct _TPrule_139* _TPPrule_139;
typedef struct _TPrule_138* _TPPrule_138;
typedef struct _TPrule_137* _TPPrule_137;
typedef struct _TPrule_136* _TPPrule_136;
typedef struct _TPrule_135* _TPPrule_135;
typedef struct _TPrule_134* _TPPrule_134;
typedef struct _TPrule_133* _TPPrule_133;
typedef struct _TPrule_132* _TPPrule_132;
typedef struct _TPrule_131* _TPPrule_131;
typedef struct _TPrule_130* _TPPrule_130;
typedef struct _TPrule_129* _TPPrule_129;
typedef struct _TPrule_128* _TPPrule_128;
typedef struct _TPrule_127* _TPPrule_127;
typedef struct _TPrule_126* _TPPrule_126;
typedef struct _TPrule_125* _TPPrule_125;
typedef struct _TPrule_124* _TPPrule_124;
typedef struct _TPrule_123* _TPPrule_123;
typedef struct _TPrule_122* _TPPrule_122;
typedef struct _TPrule_121* _TPPrule_121;
typedef struct _TPrule_120* _TPPrule_120;
typedef struct _TPrule_119* _TPPrule_119;
typedef struct _TPrule_118* _TPPrule_118;
typedef struct _TPrule_117* _TPPrule_117;
typedef struct _TPrule_116* _TPPrule_116;
typedef struct _TPrule_115* _TPPrule_115;
typedef struct _TPrule_114* _TPPrule_114;
typedef struct _TPrule_113* _TPPrule_113;
typedef struct _TPrule_112* _TPPrule_112;
typedef struct _TPrule_111* _TPPrule_111;
typedef struct _TPrule_110* _TPPrule_110;
typedef struct _TPrule_109* _TPPrule_109;
typedef struct _TPrule_108* _TPPrule_108;
typedef struct _TPrule_107* _TPPrule_107;
typedef struct _TPrule_106* _TPPrule_106;
typedef struct _TPrule_105* _TPPrule_105;
typedef struct _TPrule_104* _TPPrule_104;
typedef struct _TPrule_103* _TPPrule_103;
typedef struct _TPrule_102* _TPPrule_102;
typedef struct _TPrule_101* _TPPrule_101;
typedef struct _TPrule_100* _TPPrule_100;
typedef struct _TPrule_99* _TPPrule_99;
typedef struct _TPrule_98* _TPPrule_98;
typedef struct _TPrule_97* _TPPrule_97;
typedef struct _TPrule_96* _TPPrule_96;
typedef struct _TPrule_95* _TPPrule_95;
typedef struct _TPrule_94* _TPPrule_94;
typedef struct _TPrule_93* _TPPrule_93;
typedef struct _TPrule_92* _TPPrule_92;
typedef struct _TPrule_91* _TPPrule_91;
typedef struct _TPrule_90* _TPPrule_90;
typedef struct _TPrule_89* _TPPrule_89;
typedef struct _TPrule_88* _TPPrule_88;
typedef struct _TPrule_87* _TPPrule_87;
typedef struct _TPrule_86* _TPPrule_86;
typedef struct _TPrule_85* _TPPrule_85;
typedef struct _TPrule_84* _TPPrule_84;
typedef struct _TPrule_83* _TPPrule_83;
typedef struct _TPrule_82* _TPPrule_82;
typedef struct _TPrule_81* _TPPrule_81;
typedef struct _TPrule_80* _TPPrule_80;
typedef struct _TPrule_79* _TPPrule_79;
typedef struct _TPrule_78* _TPPrule_78;
typedef struct _TPrule_77* _TPPrule_77;
typedef struct _TPrule_76* _TPPrule_76;
typedef struct _TPrule_75* _TPPrule_75;
typedef struct _TPrule_74* _TPPrule_74;
typedef struct _TPrule_73* _TPPrule_73;
typedef struct _TPrule_72* _TPPrule_72;
typedef struct _TPrule_71* _TPPrule_71;
typedef struct _TPrule_70* _TPPrule_70;
typedef struct _TPrule_69* _TPPrule_69;
typedef struct _TPrule_68* _TPPrule_68;
typedef struct _TPrule_67* _TPPrule_67;
typedef struct _TPrule_66* _TPPrule_66;
typedef struct _TPrule_65* _TPPrule_65;

struct _TStemplate
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TStask
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSstatement
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSsources
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSsource
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSset_or_get
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSreference
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSProgram
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSvariables
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSmetaparams
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TStasks
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TScondition
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TScomparator
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TScode
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSos
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSattr_var
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSattrs
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSboolean
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSmetaparam
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSfile
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSdir
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSvalue
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSnumber
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSpair
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSsetting
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSinclude
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSparam
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSstatements
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSclass_name
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSclass
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSword
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSpairs
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TScomma
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSconfig
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSextvar
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSwords
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSvariable
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSname
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TStask_name
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_6
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_17
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPfile _desc1;
};

struct _TPrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
};

struct _TPrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
};

struct _TPrule_20
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPfile _desc1;
};

struct _TPrule_21
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_22
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPdir _desc1;
};

struct _TPrule_23
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_24
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPnumber _desc1;
};

struct _TPrule_25
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_26
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
};

struct _TPrule_27
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
};

struct _TPrule_28
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
};

struct _TPrule_29
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
};

struct _TPrule_30
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_31
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_32
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_33
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_34
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_35
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_36
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
};

struct _TPrule_37
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass_name _desc1;
_TSPparam _desc2;
_TSPstatements _desc3;
};

struct _TPrule_38
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_39
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass_name _desc1;
_TSPparam _desc2;
_TSPstatements _desc3;
};

struct _TPrule_40
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass_name _desc1;
_TSPclass_name _desc2;
_TSPstatements _desc3;
};

struct _TPrule_41
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass_name _desc1;
_TSPstatements _desc2;
};

struct _TPrule_42
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
};

struct _TPrule_43
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
_TSPcomma _desc2;
_TSPwords _desc3;
};

struct _TPrule_44
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_45
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
_TSPcomma _desc2;
_TSPpairs _desc3;
};

struct _TPrule_46
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_47
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPextvar _desc1;
};

struct _TPrule_48
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
};

struct _TPrule_49
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPwords _desc1;
};

struct _TPrule_50
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_51
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_52
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
};

struct _TPrule_53
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_54
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_55
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_56
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_57
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_58
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_59
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_60
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_61
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_62
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_63
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_64
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_174
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_173
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPcomma _desc2;
_TSPvariables _desc3;
};

struct _TPrule_172
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
};

struct _TPrule_171
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPword _desc1;
};

struct _TPrule_170
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
};

struct _TPrule_169
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtemplate _desc1;
};

struct _TPrule_168
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsources _desc1;
};

struct _TPrule_167
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsource _desc1;
};

struct _TPrule_166
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPset_or_get _desc1;
};

struct _TPrule_165
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPreference _desc1;
};

struct _TPrule_164
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvalue _desc1;
};

struct _TPrule_163
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPos _desc1;
};

struct _TPrule_162
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_161
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPmetaparam _desc1;
};

struct _TPrule_160
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_159
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_158
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPextvar _desc1;
};

struct _TPrule_157
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPboolean _desc1;
};

struct _TPrule_156
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_155
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtask_name _desc1;
_TSPconfig _desc2;
};

struct _TPrule_154
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtask _desc1;
_TSPtasks _desc2;
};

struct _TPrule_153
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtask _desc1;
};

struct _TPrule_152
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_151
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtask _desc1;
};

struct _TPrule_150
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPstatement _desc1;
_TSPstatements _desc2;
};

struct _TPrule_149
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_148
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPinclude _desc1;
};

struct _TPrule_147
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPcondition _desc1;
};

struct _TPrule_146
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass _desc1;
};

struct _TPrule_145
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattr_var _desc1;
};

struct _TPrule_144
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsource _desc1;
_TSPsource _desc2;
};

struct _TPrule_143
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_142
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_141
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_140
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_139
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_138
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_137
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_136
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_135
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_134
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_133
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_132
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_131
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_130
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_129
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_128
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_127
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_126
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_125
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_124
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_123
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_122
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_121
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_120
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_119
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_118
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_117
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_116
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_115
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_114
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_113
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_112
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_111
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_110
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_109
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_108
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_107
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
};

struct _TPrule_106
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPcomparator _desc2;
_TSPvariable _desc3;
};

struct _TPrule_105
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPmetaparams _desc1;
};

struct _TPrule_104
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG1 _desc1;
};

struct _TPrule_103
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariables _desc1;
};

struct _TPrule_102
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattrs _desc1;
};

struct _TPrule_101
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPpair _desc1;
_TSPpairs _desc2;
};

struct _TPrule_100
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPpair _desc1;
};

struct _TPrule_99
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsetting _desc1;
_TSPvalue _desc2;
_TSPcomma _desc3;
};

struct _TPrule_98
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_97
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_96
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_95
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPpairs _desc2;
};

struct _TPrule_94
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPmetaparam _desc1;
_TSPcomma _desc2;
_TSPmetaparams _desc3;
};

struct _TPrule_93
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPmetaparam _desc1;
};

struct _TPrule_92
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvalue _desc1;
};

struct _TPrule_91
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvalue _desc1;
};

struct _TPrule_90
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvalue _desc1;
};

struct _TPrule_89
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
};

struct _TPrule_88
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
_TSPvariable _desc2;
};

struct _TPrule_87
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG1 _desc1;
_TSPclass _desc2;
};

struct _TPrule_86
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPclass _desc1;
};

struct _TPrule_85
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
_TSPname _desc2;
};

struct _TPrule_84
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPname _desc1;
};

struct _TPrule_83
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPpairs _desc1;
};

struct _TPrule_82
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPcode _desc1;
_TSPtasks _desc2;
};

struct _TPrule_81
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_80
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_79
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_78
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_77
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_76
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_75
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_74
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPcomparator _desc2;
_TSPword _desc3;
};

struct _TPrule_73
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPcomparator _desc2;
_TSPnumber _desc3;
};

struct _TPrule_72
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPmetaparam _desc1;
};

struct _TPrule_71
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_70
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPword _desc2;
_TSPvalue _desc3;
};

struct _TPrule_69
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPos _desc2;
};

struct _TPrule_68
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPnumber _desc2;
};

struct _TPrule_67
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPvariable _desc1;
_TSPname _desc2;
};

struct _TPrule_66
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattr_var _desc1;
_TSPcomma _desc2;
_TSPattrs _desc3;
};

struct _TPrule_65
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattr_var _desc1;
};

#undef _NODECOMMON
#endif
