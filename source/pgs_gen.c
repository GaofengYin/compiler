/* $Id: StructConn,v 1.13 1998/10/12 06:09:57 tony Exp $ */
#include "gsdescr.h"
#include "treestack.h"
#include "HEAD.h"

#define TokenStack(i)	(ZAttributKeller[(i)])

#ifdef RIGHTCOORD
extern POSITION rightpos;
#endif

#if defined(__cplusplus) || defined(__STDC__) 
void
StrukturAnknuepfung(unsigned PR, GRUNDSYMBOLDESKRIPTOR *ZAttributKeller)
#else
void
StrukturAnknuepfung(PR, ZAttributKeller)
unsigned  PR;
register GRUNDSYMBOLDESKRIPTOR  *ZAttributKeller;
#endif
{
  curpos = ZAttributKeller->Pos;
#ifdef RIGHTCOORD
  RLineOf (curpos) = RLineOf (rightpos);
  RColOf (curpos) = RColOf (rightpos);
#ifdef MONITOR
  RCumColOf (curpos) = RCumColOf (rightpos);
#endif
#endif
  switch (PR) {
  case 1: _nst[_nsp]=Mkrule_86(&curpos, _nst[_nsp+0]); break;
  case 2: _nst[_nsp]=Mkrule_52(&curpos, _nst[_nsp+0]); break;
  case 3: _nst[_nsp]=Mkrule_38(&curpos, _nst[_nsp+0]); break;
  case 4: _nsp -= 1;_nst[_nsp]=Mkrule_87(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 5: _nst[_nsp]=Mkrule_102(&curpos, _nst[_nsp+0]); break;
  case 6: _nst[_nsp]=Mkrule_103(&curpos, _nst[_nsp+0]); break;
  case 7: _nst[_nsp]=Mkrule_145(&curpos, _nst[_nsp+0]); break;
  case 8: _nst[_nsp]=Mkrule_146(&curpos, _nst[_nsp+0]); break;
  case 9: _nst[_nsp]=Mkrule_147(&curpos, _nst[_nsp+0]); break;
  case 10: _nst[_nsp]=Mkrule_148(&curpos, _nst[_nsp+0]); break;
  case 11: _nst[_nsp]=Mkrule_151(&curpos, _nst[_nsp+0]); break;
  case 12: _nst[_nsp]=Mkrule_36(&curpos, _nst[_nsp+0]); break;
  case 13: _nsp -= 1;_nst[_nsp]=Mkrule_150(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 14: _nsp -= 2;_nst[_nsp]=Mkrule_66(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 15: _nsp -= 1;_nst[_nsp]=Mkrule_67(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 16: _nsp -= 1;_nst[_nsp]=Mkrule_68(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 17: _nsp -= 1;_nst[_nsp]=Mkrule_69(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 18: _nsp -= 2;_nst[_nsp]=Mkrule_173(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 19: _nst[_nsp]=Mkrule_83(&curpos, _nst[_nsp+0]); break;
  case 20: _nsp -= 1;_nst[_nsp]=Mkrule_101(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 21: _nsp -= 2;_nst[_nsp]=Mkrule_43(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 22: _nst[_nsp]=Mkrule_24(&curpos, _nst[_nsp+0]); break;
  case 23: _nst[_nsp]=Mkrule_163(&curpos, _nst[_nsp+0]); break;
  case 24: _nst[_nsp]=Mkrule_171(&curpos, _nst[_nsp+0]); break;
  case 25: _nst[_nsp]=Mkrule_157(&curpos, _nst[_nsp+0]); break;
  case 26: _nst[_nsp]=Mkrule_161(&curpos, _nst[_nsp+0]); break;
  case 27: _nst[_nsp]=Mkrule_22(&curpos, _nst[_nsp+0]); break;
  case 28: _nst[_nsp]=Mkrule_158(&curpos, _nst[_nsp+0]); break;
  case 29: _nst[_nsp]=Mkrule_20(&curpos, _nst[_nsp+0]); break;
  case 30: _nst[_nsp]=Mkrule_165(&curpos, _nst[_nsp+0]); break;
  case 31: _nst[_nsp]=Mkrule_166(&curpos, _nst[_nsp+0]); break;
  case 32: _nst[_nsp]=Mkrule_167(&curpos, _nst[_nsp+0]); break;
  case 33: _nst[_nsp]=Mkrule_168(&curpos, _nst[_nsp+0]); break;
  case 34: _nst[_nsp]=Mkrule_169(&curpos, _nst[_nsp+0]); break;
  case 35: _nsp -= 1;_nst[_nsp]=Mkrule_154(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 36: _nsp -= 2;_nst[_nsp]=Mkrule_45(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 37: _nst[_nsp]=Mkrule_89(&curpos, _nst[_nsp+0]); break;
  case 38: _nsp -= 1;_nst[_nsp]=Mkrule_28(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 39: _nsp -= 1;_nst[_nsp]=Mkrule_29(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 40: _nsp -= 2;_nst[_nsp]=Mkrule_99(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 41: _nsp -= 1;_nst[_nsp]=Mkrule_88(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 42: _nsp -= 2;_nst[_nsp]=Mkrule_94(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 43: _nsp -= 2;_nst[_nsp]=Mkrule_106(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 44: _nsp -= 1;_nst[_nsp]=Mkrule_26(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 45: _nsp -= 1;_nst[_nsp]=Mkrule_27(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 46: _incrnodestack();_nst[_nsp]=Mkrule_71(&curpos, Mkword_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 47: _incrnodestack();_nst[_nsp]=Mkrule_53(&curpos, Mkword_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 48: _incrnodestack();_nst[_nsp]=Mkrule_51(&curpos, Mkdir_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 49: _incrnodestack();_nst[_nsp]=Mkrule_55(&curpos, Mkfile_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 50: _nst[_nsp]=Mkrule_104(&curpos, _nst[_nsp+0]); break;
  case 52: _incrnodestack();_nst[_nsp]=Mkrule_174(&curpos, Mkword_ident(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 53: _incrnodestack();_nst[_nsp]=Mkrule_149(&curpos); break;
  case 54: _incrnodestack();_nst[_nsp]=Mkrule_62(&curpos); break;
  case 55: _incrnodestack();_nst[_nsp]=Mkrule_61(&curpos); break;
  case 56: _incrnodestack();_nst[_nsp]=Mkrule_63(&curpos); break;
  case 57: _incrnodestack();_nst[_nsp]=Mkrule_60(&curpos); break;
  case 58: _incrnodestack();_nst[_nsp]=Mkrule_64(&curpos); break;
  case 59: _incrnodestack();_nst[_nsp]=Mkrule_44(&curpos, Mkword_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 60: _nst[_nsp]=Mkrule_49(&curpos, _nst[_nsp+0]); break;
  case 61: _nst[_nsp]=Mkrule_54(&curpos, Mkplica(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0))), _nst[_nsp+0], Mkplica(&(T_POS(TokenStack(2))), T_ATTR(TokenStack(2)))); break;
  case 62: _nst[_nsp]=Mkrule_47(&curpos, _nst[_nsp+0]); break;
  case 63: _nst[_nsp]=Mkrule_48(&curpos, _nst[_nsp+0]); break;
  case 64: _incrnodestack();_nst[_nsp]=Mkrule_50(&curpos, Mkdir_ident(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 65: _incrnodestack();_nst[_nsp]=Mkrule_56(&curpos, Mkfile_ident(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 66: _incrnodestack();_nst[_nsp]=Mkrule_46(&curpos, Mkfill(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 67: _incrnodestack();_nst[_nsp]=Mkrule_57(&curpos, Mkword_ident(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 68: _nst[_nsp]=Mkrule_65(&curpos, _nst[_nsp+0]); break;
  case 69: _incrnodestack();_nst[_nsp]=Mkrule_76(&curpos); break;
  case 70: _incrnodestack();_nst[_nsp]=Mkrule_77(&curpos); break;
  case 71: _incrnodestack();_nst[_nsp]=Mkrule_78(&curpos); break;
  case 72: _incrnodestack();_nst[_nsp]=Mkrule_75(&curpos); break;
  case 73: _nst[_nsp]=Mkrule_172(&curpos, _nst[_nsp+0]); break;
  case 74: _nsp -= 1;_nst[_nsp]=Mkrule_41(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 75: _incrnodestack();_nst[_nsp]=Mkrule_25(&curpos, Mknum_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 76: _incrnodestack();_nst[_nsp]=Mkrule_79(&curpos); break;
  case 77: _incrnodestack();_nst[_nsp]=Mkrule_108(&curpos); break;
  case 78: _incrnodestack();_nst[_nsp]=Mkrule_109(&curpos); break;
  case 79: _incrnodestack();_nst[_nsp]=Mkrule_110(&curpos); break;
  case 80: _incrnodestack();_nst[_nsp]=Mkrule_111(&curpos); break;
  case 81: _incrnodestack();_nst[_nsp]=Mkrule_112(&curpos); break;
  case 82: _incrnodestack();_nst[_nsp]=Mkrule_113(&curpos); break;
  case 83: _incrnodestack();_nst[_nsp]=Mkrule_114(&curpos); break;
  case 84: _incrnodestack();_nst[_nsp]=Mkrule_115(&curpos); break;
  case 85: _incrnodestack();_nst[_nsp]=Mkrule_116(&curpos); break;
  case 86: _incrnodestack();_nst[_nsp]=Mkrule_117(&curpos); break;
  case 87: _incrnodestack();_nst[_nsp]=Mkrule_118(&curpos); break;
  case 88: _incrnodestack();_nst[_nsp]=Mkrule_119(&curpos); break;
  case 89: _incrnodestack();_nst[_nsp]=Mkrule_120(&curpos); break;
  case 90: _incrnodestack();_nst[_nsp]=Mkrule_121(&curpos); break;
  case 91: _incrnodestack();_nst[_nsp]=Mkrule_122(&curpos); break;
  case 92: _incrnodestack();_nst[_nsp]=Mkrule_123(&curpos); break;
  case 93: _incrnodestack();_nst[_nsp]=Mkrule_33(&curpos); break;
  case 94: _incrnodestack();_nst[_nsp]=Mkrule_35(&curpos); break;
  case 95: _incrnodestack();_nst[_nsp]=Mkrule_124(&curpos); break;
  case 96: _incrnodestack();_nst[_nsp]=Mkrule_125(&curpos); break;
  case 97: _incrnodestack();_nst[_nsp]=Mkrule_126(&curpos); break;
  case 98: _incrnodestack();_nst[_nsp]=Mkrule_127(&curpos); break;
  case 99: _incrnodestack();_nst[_nsp]=Mkrule_128(&curpos); break;
  case 100: _incrnodestack();_nst[_nsp]=Mkrule_34(&curpos); break;
  case 101: _incrnodestack();_nst[_nsp]=Mkrule_129(&curpos); break;
  case 102: _incrnodestack();_nst[_nsp]=Mkrule_130(&curpos); break;
  case 103: _incrnodestack();_nst[_nsp]=Mkrule_131(&curpos); break;
  case 104: _incrnodestack();_nst[_nsp]=Mkrule_132(&curpos); break;
  case 105: _incrnodestack();_nst[_nsp]=Mkrule_133(&curpos); break;
  case 106: _incrnodestack();_nst[_nsp]=Mkrule_134(&curpos); break;
  case 107: _incrnodestack();_nst[_nsp]=Mkrule_32(&curpos); break;
  case 108: _incrnodestack();_nst[_nsp]=Mkrule_135(&curpos); break;
  case 109: _incrnodestack();_nst[_nsp]=Mkrule_136(&curpos); break;
  case 110: _incrnodestack();_nst[_nsp]=Mkrule_137(&curpos); break;
  case 111: _incrnodestack();_nst[_nsp]=Mkrule_138(&curpos); break;
  case 112: _incrnodestack();_nst[_nsp]=Mkrule_139(&curpos); break;
  case 113: _incrnodestack();_nst[_nsp]=Mkrule_140(&curpos); break;
  case 114: _incrnodestack();_nst[_nsp]=Mkrule_141(&curpos); break;
  case 115: _incrnodestack();_nst[_nsp]=Mkrule_142(&curpos); break;
  case 116: _nsp -= 2;_nst[_nsp]=Mkrule_40(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 117: _incrnodestack();_nst[_nsp]=Mkrule_80(&curpos); break;
  case 118: _incrnodestack();_nst[_nsp]=Mkrule_81(&curpos); break;
  case 119: _nst[_nsp]=Mkrule_152(&curpos, _nst[_nsp+0]); break;
  case 120: _nst[_nsp]=Mkrule_59(&curpos, _nst[_nsp+0]); break;
  case 121: _nst[_nsp]=Mkrule_58(&curpos, _nst[_nsp+0]); break;
  case 122: _nst[_nsp]=Mkrule_100(&curpos, _nst[_nsp+0]); break;
  case 123: _nsp -= 1;_nst[_nsp]=Mkrule_155(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 124: _nsp -= 1;_nst[_nsp]=Mkrule_42(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 125: _nst[_nsp]=Mkrule_84(&curpos, _nst[_nsp+0]); break;
  case 126: _incrnodestack();_nst[_nsp]=Mkrule_12(&curpos); break;
  case 127: _incrnodestack();_nst[_nsp]=Mkrule_15(&curpos); break;
  case 128: _incrnodestack();_nst[_nsp]=Mkrule_23(&curpos, Mkdir_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 129: _incrnodestack();_nst[_nsp]=Mkrule_21(&curpos, Mkfile_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 130: _incrnodestack();_nst[_nsp]=Mkrule_159(&curpos, Mkfill(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 131: _incrnodestack();_nst[_nsp]=Mkrule_14(&curpos); break;
  case 132: _incrnodestack();_nst[_nsp]=Mkrule_16(&curpos); break;
  case 133: _incrnodestack();_nst[_nsp]=Mkrule_143(&curpos, Mksource_ident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 134: _incrnodestack();_nst[_nsp]=Mkrule_2(&curpos); break;
  case 135: _incrnodestack();_nst[_nsp]=Mkrule_1(&curpos); break;
  case 136: _incrnodestack();_nst[_nsp]=Mkrule_7(&curpos); break;
  case 137: _incrnodestack();_nst[_nsp]=Mkrule_160(&curpos); break;
  case 138: _incrnodestack();_nst[_nsp]=Mkrule_162(&curpos, Mkoptions(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 139: _incrnodestack();_nst[_nsp]=Mkrule_8(&curpos); break;
  case 140: _incrnodestack();_nst[_nsp]=Mkrule_5(&curpos); break;
  case 141: _incrnodestack();_nst[_nsp]=Mkrule_11(&curpos); break;
  case 142: _incrnodestack();_nst[_nsp]=Mkrule_13(&curpos); break;
  case 143: _incrnodestack();_nst[_nsp]=Mkrule_10(&curpos); break;
  case 144: _incrnodestack();_nst[_nsp]=Mkrule_9(&curpos); break;
  case 145: _incrnodestack();_nst[_nsp]=Mkrule_6(&curpos); break;
  case 146: _incrnodestack();_nst[_nsp]=Mkrule_4(&curpos); break;
  case 147: _incrnodestack();_nst[_nsp]=Mkrule_3(&curpos); break;
  case 148: _nsp -= 2;_nst[_nsp]=Mkrule_37(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 149: _nsp -= 2;_nst[_nsp]=Mkrule_39(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 150: _nst[_nsp]=Mkrule_153(&curpos, _nst[_nsp+0]); break;
  case 151: _nsp -= 1;_nst[_nsp]=Mkrule_82(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 152: _incrnodestack();_nst[_nsp]=Mkrule_96(&curpos); break;
  case 153: _incrnodestack();_nst[_nsp]=Mkrule_31(&curpos); break;
  case 154: _incrnodestack();_nst[_nsp]=Mkrule_98(&curpos); break;
  case 155: _nst[_nsp]=Mkrule_170(&curpos, _nst[_nsp+0]); break;
  case 156: _nsp -= 2;_nst[_nsp]=Mkrule_70(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 157: _nst[_nsp]=Mkrule_72(&curpos, _nst[_nsp+0]); break;
  case 158: _nsp -= 2;_nst[_nsp]=Mkrule_73(&curpos, _nst[_nsp+0], _nst[_nsp+1], Mkplica(&(T_POS(TokenStack(2))), T_ATTR(TokenStack(2))), _nst[_nsp+2], Mkplica(&(T_POS(TokenStack(4))), T_ATTR(TokenStack(4)))); break;
  case 159: _nsp -= 2;_nst[_nsp]=Mkrule_74(&curpos, _nst[_nsp+0], _nst[_nsp+1], Mkplica(&(T_POS(TokenStack(2))), T_ATTR(TokenStack(2))), _nst[_nsp+2], Mkplica(&(T_POS(TokenStack(4))), T_ATTR(TokenStack(4)))); break;
  case 160: _nst[_nsp]=Mkrule_93(&curpos, _nst[_nsp+0]); break;
  case 161: _nst[_nsp]=Mkrule_105(&curpos, _nst[_nsp+0]); break;
  case 162: _nst[_nsp]=Mkrule_164(&curpos, Mkplica(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0))), _nst[_nsp+0], Mkplica(&(T_POS(TokenStack(2))), T_ATTR(TokenStack(2)))); break;
  case 163: _nst[_nsp]=Mkrule_107(&curpos, _nst[_nsp+0]); break;
  case 165: _nsp -= 1;_nst[_nsp]=Mkrule_95(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 166: _nst[_nsp]=Mkrule_90(&curpos, _nst[_nsp+0]); break;
  case 167: _nst[_nsp]=Mkrule_91(&curpos, _nst[_nsp+0]); break;
  case 168: _nst[_nsp]=Mkrule_18(&curpos, _nst[_nsp+0]); break;
  case 169: _nst[_nsp]=Mkrule_92(&curpos, _nst[_nsp+0]); break;
  case 170: _nst[_nsp]=Mkrule_156(&curpos, _nst[_nsp+0]); break;
  case 171: _incrnodestack();_nst[_nsp]=Mkrule_30(&curpos); break;
  case 172: _incrnodestack();_nst[_nsp]=Mkrule_97(&curpos); break;
  case 173: _nsp -= 1;_nst[_nsp]=Mkrule_85(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 174: _nst[_nsp]=Mkrule_17(&curpos, _nst[_nsp+0]); break;
  case 175: _nst[_nsp]=Mkrule_19(&curpos, _nst[_nsp+0]); break;
  case 176: _nsp -= 1;_nst[_nsp]=Mkrule_144(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  } /* end switch */
}
