
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR Mktemplate ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mktask ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkstatement ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mksources ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mksource ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkset_or_get ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkreference ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkProgram ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkvariables ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkmetaparams ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG2 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG1 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mktasks ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkcondition ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkcomparator ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkcode ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkos ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkattr_var ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkattrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkboolean ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkmetaparam ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkfile ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkdir ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkvalue ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mknumber ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkpair ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mksetting ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkinclude ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkparam ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkstatements ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkclass_name ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkclass ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkword ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkpairs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkcomma ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkconfig ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkextvar ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkwords ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkvariable ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkname ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mktask_name ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_20 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_21 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_22 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_23 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_24 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_25 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_26 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_27 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_28 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_29 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_30 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_31 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_32 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_33 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_34 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_35 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_36 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_37 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_38 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_39 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_40 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_41 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_42 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_43 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_44 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_45 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_46 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_47 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_48 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_49 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_50 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_51 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_52 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_53 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_54 ELI_ARG((POSITION *_coordref, int _TERM1, NODEPTR _desc1, int _TERM2));
extern NODEPTR Mkrule_55 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_56 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_57 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_58 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_59 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_60 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_61 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_62 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_63 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_64 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_174 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_173 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_172 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_171 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_170 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_169 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_168 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_167 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_166 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_165 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_164 ELI_ARG((POSITION *_coordref, int _TERM1, NODEPTR _desc1, int _TERM2));
extern NODEPTR Mkrule_163 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_162 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_161 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_160 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_159 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_158 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_157 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_156 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_155 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_154 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_153 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_152 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_151 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_150 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_149 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_148 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_147 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_146 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_145 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_144 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_143 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_142 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_141 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_140 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_139 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_138 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_137 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_136 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_135 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_134 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_133 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_132 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_131 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_130 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_129 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_128 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_127 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_126 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_125 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_124 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_123 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_122 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_121 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_120 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_119 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_118 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_117 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_116 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_115 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_114 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_113 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_112 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_111 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_110 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_109 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_108 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_107 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_106 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_105 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_104 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_103 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_102 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_101 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_100 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_99 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_98 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_97 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_96 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_95 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_94 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_93 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_92 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_91 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_90 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_89 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_88 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_87 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_86 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_85 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_84 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_83 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_82 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_81 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_80 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_79 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_78 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_77 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_76 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_75 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_74 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3, int _TERM2));
extern NODEPTR Mkrule_73 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3, int _TERM2));
extern NODEPTR Mkrule_72 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_71 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_70 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_69 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_68 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_67 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_66 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_65 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
#define Mksource_ident(pos,val) (val)
#define Mkoptions(pos,val) (val)
#define Mkplica(pos,val) (val)
#define Mkfill(pos,val) (val)
#define Mkword_ident(pos,val) (val)
#define Mknum_ident(pos,val) (val)
#define Mkdir_ident(pos,val) (val)
#define Mkfile_ident(pos,val) (val)
#endif
