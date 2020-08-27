switch (CaseTbl[c = *p++]) {
case 0:	/* sentinel - probably EOB */
  if (c == '\0') {
    p = TokenStart = TokenEnd = auxNUL(TokenStart, 0);
    if (*p) extcode = NORETURN;
    else {
      p = TokenStart = TokenEnd = auxEOF(TokenStart, 0);
      if (*p) extcode = NORETURN;
      else { extcode = EOFTOKEN; EndOfText(p, 0, &extcode, v); }
    }
    goto done;
  } else {
    obstack_grow(Csm_obstk, "char '", 6);
    obstack_cchgrow(Csm_obstk, c);
    message(
      ERROR,
      (char *)obstack_copy0(Csm_obstk, "' is not a token", 16),
      0,
      &curpos);
    TokenEnd = p;
    continue;
  }
  
case 1:	/* space */
  while (scanTbl[c = *p++] & 1<<0) ;
  TokenEnd = p - 1;
  continue;
case 2:	/* tab */
  do { StartLine -= TABSIZE(p - StartLine); }
  while (scanTbl[c = *p++] & 1<<1);
  TokenEnd = p - 1;
  continue;
case 4:	/* carriage return */
  if (*p == '\n') { TokenEnd = p; continue; }
case 3:	/* newline */
  do { LineNum++; } while (scanTbl[c = *p++] & 1<<2);
  StartLine = (TokenEnd = p - 1) - 1;
  continue;

case 5:	/* Entered on:  + A-B D-E G I-O Q-R T-Z */
	St_11:
		/*  + _*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on:  0-5 7-9 */
	St_15:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 6);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 36;
			mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 7:	/* Entered on:  j-k q v-z */
	St_38:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 8:	/* Entered on:  - _ */
	St_13:
		/*  _*/
		while(scanTbl[(c= *p++)+256] & 1<< 2);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  - a-z */
			goto St_55;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 9:	/* Entered on: u */
	St_47:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_113;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 10:	/* Entered on: t */
	St_46:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 6){ /*  b-d f-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_112;}
		else if(c ==101) {			goto St_111;}
		else if(c ==97) {			goto St_110;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 11:	/* Entered on: s */
	St_45:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 7){ /*  a-d f-g i-n p-s v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_109;}
		else if(c ==116) {			goto St_108;}
		else if(c ==111) {			goto St_107;}
		else if(c ==104) {			goto St_106;}
		else if(c ==101) {			goto St_105;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 12:	/* Entered on: r */
	St_44:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 0){ /*  a-d f-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_104;}
		else if(c ==101) {			goto St_103;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 13:	/* Entered on: p */
	St_43:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 1){ /*  b-q s-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_102;}
		else if(c ==114) {			goto St_101;}
		else if(c ==97) {			goto St_100;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 14:	/* Entered on: o */
	St_42:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 2){ /*  a-m o q-v x-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==119) {			goto St_99;}
		else if(c ==112) {			goto St_98;}
		else if(c ==110) {			goto St_97;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 15:	/* Entered on: n */
	St_41:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 3){ /*  b-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_96;}
		else if(c ==97) {			goto St_95;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 16:	/* Entered on: m */
	St_40:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_94;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 17:	/* Entered on: l */
	St_39:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_93;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 18:	/* Entered on: i */
	St_37:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 6){ /*  a-e g-l o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_92;}
		else if(c ==110) {			goto St_91;}
		else if(c ==109) {			goto St_90;}
		else if(c ==102) {			goto St_89;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 19:	/* Entered on: h */
	St_36:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 3){ /*  b-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_88;}
		else if(c ==97) {			goto St_87;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 20:	/* Entered on: g */
	St_35:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 7){ /*  a-d f-h j-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_86;}
		else if(c ==105) {			goto St_85;}
		else if(c ==101) {			goto St_84;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 21:	/* Entered on: f */
	St_34:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 0){ /*  b-h j-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_83;}
		else if(c ==105) {			goto St_82;}
		else if(c ==97) {			goto St_81;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 22:	/* Entered on: e */
	St_33:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_80;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 23:	/* Entered on: d */
	St_32:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 2){ /*  a-d f-h j-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_79;}
		else if(c ==105) {			goto St_78;}
		else if(c ==101) {			goto St_77;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 24:	/* Entered on: c */
	St_31:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 3){ /*  a-g i-k m-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_76;}
		else if(c ==108) {			goto St_75;}
		else if(c ==104) {			goto St_74;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 25:	/* Entered on: b */
	St_30:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_73;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 26:	/* Entered on: a */
	St_29:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 4){ /*  a c-k m-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_72;}
		else if(c ==108) {			goto St_71;}
		else if(c ==98) {			goto St_70;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 27:	/* Entered on: S */
	St_26:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  - A-Z a-d f-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==101) {			goto St_67;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 28:	/* Entered on: P */
	St_25:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  - A-Z b-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==97) {			goto St_66;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 29:	/* Entered on: H */
	St_24:
		if( scanTbl[(c= *p++)+768] & 1<< 7){ /*  - A-Z a-n p-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==111) {			goto St_65;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 30:	/* Entered on: F */
	St_23:
		if( scanTbl[(c= *p++)+1024] & 1<< 0){ /*  - A-Z a-h j-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==105) {			goto St_64;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 31:	/* Entered on: C */
	St_22:
		if( scanTbl[(c= *p++)+1024] & 1<< 1){ /*  - A-Z a-d f-k m-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==108) {			goto St_63;}
		else if(c ==101) {			goto St_62;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 32:	/* Entered on: = */
	St_20:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else if(c ==62) {			goto St_61;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 2;
			goto done;
			}

case 33:	/* Entered on: 6 */
	St_16:
		if( scanTbl[(c= *p++)+0] & 1<< 6){ /*  0-9 */
			goto St_15;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 49;
			goto done;
			}

case 34:	/* Entered on: / */
	St_14:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  $ 0-: A-Z */
			goto St_56;}
		else if( scanTbl[c+1024] & 1<< 4){ /*  - _ a-z */
			goto St_58;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else if(c ==94) {		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_60;}
		else if(c ==46) {			goto St_59;}
		else if(c ==40) {		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_57;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			goto done;
			}

case 35:	/* Entered on: , */
	St_12:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 17;
			goto done;
			}

case 36:	/* Entered on: * */
	St_10:
		/*  * - / _ a-z*/
		while(scanTbl[(c= *p++)+1024] & 1<< 5);--p;
		if((c= *p++) ==46) {
		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_50;}
		else {TokenEnd=TokenStart;--p; goto fallback; }


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  !-" $ '-) :-< ? [ ] { } */
}
	St_50:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  . 0-9 a-z */
			goto St_114;}
		else {--p; goto fallback; }
	St_114:
		/*  . 0-9 a-z*/
		while(scanTbl[(c= *p++)+1024] & 1<< 6);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 25;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_54:
		/*  , = a-z*/
		while(scanTbl[(c= *p++)+1024] & 1<< 2);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 97;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_57:
		if((c= *p++) ==99) {			goto St_117;}
		else {--p; goto fallback; }
	St_117:
		if((c= *p++) ==101) {			goto St_183;}
		else {--p; goto fallback; }
	St_183:
		if((c= *p++) ==110) {			goto St_245;}
		else {--p; goto fallback; }
	St_245:
		if((c= *p++) ==116) {			goto St_299;}
		else {--p; goto fallback; }
	St_299:
		if((c= *p++) ==111) {			goto St_347;}
		else {--p; goto fallback; }
	St_347:
		if((c= *p++) ==115) {			goto St_380;}
		else {--p; goto fallback; }
	St_380:
		if((c= *p++) ==124) {			goto St_395;}
		else {--p; goto fallback; }
	St_395:
		if((c= *p++) ==82) {			goto St_404;}
		else {--p; goto fallback; }
	St_404:
		if((c= *p++) ==101) {			goto St_410;}
		else {--p; goto fallback; }
	St_410:
		if((c= *p++) ==100) {			goto St_412;}
		else {--p; goto fallback; }
	St_412:
		if((c= *p++) ==72) {			goto St_414;}
		else {--p; goto fallback; }
	St_414:
		if((c= *p++) ==97) {			goto St_415;}
		else {--p; goto fallback; }
	St_415:
		if((c= *p++) ==116) {			goto St_416;}
		else {--p; goto fallback; }
	St_416:
		if((c= *p++) ==41) {			goto St_417;}
		else {--p; goto fallback; }
	St_417:
		if((c= *p++) ==47) {			goto St_418;}
		else {--p; goto fallback; }
	St_418:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 54;
			goto done;
	St_59:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  . 0-9 a-z */
			goto St_119;}
		else if( scanTbl[c+1024] & 1<< 7){ /*  $ - : A-Z _ */
			goto St_56;}
		else if(c ==47) {		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_116;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_116:
		if( scanTbl[(c= *p++)+1280] & 1<< 0){ /*  $ --. 0-: A-Z _ a-z */
			goto St_56;}
		else {--p; goto fallback; }
	St_56:
		/*  $ --. 0-: A-Z _ a-z*/
		while(scanTbl[(c= *p++)+1280] & 1<< 0);--p;
		if((c= *p++) ==47) {		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_116;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_119:
		/*  . 0-9 a-z*/
		while(scanTbl[(c= *p++)+1024] & 1<< 6);--p;
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  $ - : A-Z _ */
			goto St_56;}
		else if(c ==47) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_116;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_60:
		if((c= *p++) ==54) {			goto St_121;}
		else if(c ==53) {			goto St_120;}
		else {--p; goto fallback; }
	St_120:
		if((c= *p++) ==92) {			goto St_184;}
		else {--p; goto fallback; }
	St_184:
		if((c= *p++) ==46) {			goto St_246;}
		else {--p; goto fallback; }
	St_246:
		if((c= *p++) ==47) {			goto St_300;}
		else {--p; goto fallback; }
	St_300:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 47;
			goto done;
	St_121:
		if((c= *p++) ==92) {			goto St_185;}
		else {--p; goto fallback; }
	St_185:
		if((c= *p++) ==46) {			goto St_247;}
		else {--p; goto fallback; }
	St_247:
		if((c= *p++) ==47) {			goto St_301;}
		else {--p; goto fallback; }
	St_301:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 48;
			goto done;
	St_58:
		/*  - _ a-z*/
		while(scanTbl[(c= *p++)+1024] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  $ 0-: A-Z */
			goto St_56;}
		else if(c ==47) {		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_118;}
		else if(c ==46) {			goto St_59;}
		else if(c ==42) {		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_118:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  $ 0-: A-Z */
			goto St_56;}
		else if( scanTbl[c+1024] & 1<< 4){ /*  - _ a-z */
			goto St_58;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
			goto St_10;}
		else if(c ==46) {			goto St_59;}
		else {--p; goto fallback; }
	St_61:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 39;
			goto done;
	St_53:
		if((c= *p++) ==58) {			goto St_115;}
		else {--p; goto fallback; }
	St_115:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  $ - 0-9 A-Z a-z */
			goto St_51;}
		else {--p; goto fallback; }
	St_51:
		/*  $ - 0-9 A-Z a-z*/
		while(scanTbl[(c= *p++)+1280] & 1<< 1);--p;
		if((c= *p++) ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_62:
		if( scanTbl[(c= *p++)+1280] & 1<< 2){ /*  - A-Z a-m o-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==110) {			goto St_122;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_122:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  - A-Z a-s u-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==116) {			goto St_186;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_186:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  - A-N P-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==79) {			goto St_248;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_248:
		if( scanTbl[(c= *p++)+1280] & 1<< 5){ /*  - A-R T-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==83) {			goto St_302;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_302:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 53;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 53;
			goto done;
			}
	St_52:
		/*  - A-Z a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_63:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  - A-Z b-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==97) {			goto St_123;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_123:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  - A-Z a-r t-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==115) {			goto St_187;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_187:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  - A-Z a-r t-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==115) {			goto St_249;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_249:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 27;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 27;
			goto done;
			}
	St_64:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  - A-Z a-k m-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==108) {			goto St_124;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_124:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  - A-Z a-d f-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==101) {			goto St_188;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_188:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 30;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 30;
			goto done;
			}
	St_65:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  - A-Z a-r t-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==115) {			goto St_125;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_125:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  - A-Z a-s u-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==116) {			goto St_189;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_189:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 32;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 32;
			goto done;
			}
	St_66:
		if( scanTbl[(c= *p++)+1536] & 1<< 0){ /*  - A-Z a-b d-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==99) {			goto St_126;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_126:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  - A-Z a-j l-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==107) {			goto St_190;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_190:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  - A-Z b-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==97) {			goto St_250;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_250:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  - A-Z a-f h-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==103) {			goto St_303;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_303:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  - A-Z a-d f-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==101) {			goto St_348;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_348:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 33;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 33;
			goto done;
			}
	St_67:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  - A-Z a-q s-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==114) {			goto St_127;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_127:
		if( scanTbl[(c= *p++)+1536] & 1<< 4){ /*  - A-Z a-u w-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==118) {			goto St_191;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_191:
		if( scanTbl[(c= *p++)+1024] & 1<< 0){ /*  - A-Z a-h j-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==105) {			goto St_251;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_251:
		if( scanTbl[(c= *p++)+1536] & 1<< 0){ /*  - A-Z a-b d-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==99) {			goto St_304;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_304:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  - A-Z a-d f-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==101) {			goto St_349;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_349:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  - A-Z a-z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+0] & 1<< 3){ /*  + _ */
			goto St_11;}
		else if(c ==58) {		extcode = 34;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 34;
			goto done;
			}
	St_55:
		/*  - a-z*/
		while(scanTbl[(c= *p++)+256] & 1<< 3);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_68:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  - a-z */
			goto St_128;}
		else if( scanTbl[c+1536] & 1<< 5){ /*  * / _ */
			goto St_10;}
		else if(c ==46) {			goto St_50;}
		else {--p; goto fallback; }
	St_128:
		/*  - a-z*/
		while(scanTbl[(c= *p++)+256] & 1<< 3);--p;
		if( scanTbl[(c= *p++)+1536] & 1<< 6){ /*  * _ */
		extcode = 35;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==47) {		extcode = 35;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 35;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 35;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_70:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_129;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_129:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_192;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_192:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_252;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_252:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_305;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_305:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 93;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 93;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 93;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_350;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 93;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 93;
			goto done;
			}
	St_350:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 106;
			goto done;
			}
	St_69:
		/*  a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 7);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_71:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_130;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_130:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_193;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_193:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_253;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_253:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 50;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 50;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 50;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 50;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 50;
			goto done;
			}
	St_72:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 2){ /*  a c-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==98) {			goto St_131;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_131:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_194;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_194:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_254;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_254:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_306;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_306:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 51;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 51;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 51;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 51;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 51;
			goto done;
			}
	St_73:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_132;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_132:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 4){ /*  a-j l-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==107) {			goto St_195;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_195:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_255;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_255:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_307;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_307:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 52;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 52;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 52;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 52;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 52;
			goto done;
			}
	St_74:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_133;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_133:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_196;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_196:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 7){ /*  a-f h-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==103) {			goto St_256;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_256:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_308;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_308:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_351;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_351:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 55;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 55;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 55;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 55;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 55;
			goto done;
			}
	St_75:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_134;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_134:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_197;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_197:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_257;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_257:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			goto done;
			}
	St_76:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 0){ /*  a-l o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_136;}
		else if(c ==109) {			goto St_135;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_135:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 1){ /*  a-l n-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==109) {			goto St_198;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_198:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 2){ /*  b-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_259;}
		else if(c ==97) {			goto St_258;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_258:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_309;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_309:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_352;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_352:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 56;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 56;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 56;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 56;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 56;
			goto done;
			}
	St_259:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_310;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_310:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_353;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_353:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 57;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 57;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 57;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 57;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 57;
			goto done;
			}
	St_136:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_199;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_199:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_260;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_260:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 4){ /*  a-m o-w y-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==120) {			goto St_312;}
		else if(c ==110) {			goto St_311;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_311:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_354;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_354:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 58;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 58;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 58;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 58;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 58;
			goto done;
			}
	St_312:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_355;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_355:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 59;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 59;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 59;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 59;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 59;
			goto done;
			}
	St_77:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 5){ /*  a-e g-u w-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==118) {			goto St_138;}
		else if(c ==102) {			goto St_137;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_137:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 6){ /*  b-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_201;}
		else if(c ==97) {			goto St_200;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_200:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_261;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_261:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_313;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_313:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_356;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_356:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 60;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 60;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 60;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 60;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 60;
			goto done;
			}
	St_201:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_262;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_262:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_314;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_314:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_357;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 11;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 11;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 11;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 11;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			goto done;
			}
	St_357:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 15;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 15;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 15;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 15;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 15;
			goto done;
			}
	St_138:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_202;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_202:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_263;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_263:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_315;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_315:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 61;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 61;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 61;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 61;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 61;
			goto done;
			}
	St_78:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_139;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_139:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_203;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_203:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_264;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_264:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_316;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_316:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_358;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_358:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_381;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_381:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 1){ /*  a-x z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==121) {			goto St_396;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_396:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 94;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 94;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 94;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 94;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 94;
			goto done;
			}
	St_79:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 1){ /*  a-l n-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==109) {			goto St_140;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_140:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_204;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_204:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 62;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 62;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 62;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 62;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 62;
			goto done;
			}
	St_80:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 2){ /*  b-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_142;}
		else if(c ==97) {			goto St_141;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_141:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 2){ /*  a c-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==98) {			goto St_205;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_205:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_265;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_265:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_317;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_317:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 63;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 63;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 63;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 63;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 63;
			goto done;
			}
	St_142:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_206;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_206:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_266;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_266:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_318;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_318:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 64;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 64;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 64;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 64;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 64;
			goto done;
			}
	St_81:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_143;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_143:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_207;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_207:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_267;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_267:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 5;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 5;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 5;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_319;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 5;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 5;
			goto done;
			}
	St_319:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 41;
			goto done;
			}
	St_82:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_144;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_144:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_208;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_208:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 87;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 87;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 87;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 87;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 87;
			goto done;
			}
	St_83:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_145;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_145:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 1){ /*  a-x z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==121) {			goto St_209;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_209:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_268;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_268:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_320;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_320:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 65;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 65;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 65;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 65;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 65;
			goto done;
			}
	St_84:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_146;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_146:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 45;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 45;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 45;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 45;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 45;
			goto done;
			}
	St_85:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_147;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_147:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 66;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 66;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 66;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 66;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 66;
			goto done;
			}
	St_86:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_148;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_148:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_210;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_210:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_269;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_269:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 38;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 38;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 38;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 38;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 38;
			goto done;
			}
	St_87:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_149;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_149:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 3){ /*  a-q t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_212;}
		else if(c ==114) {			goto St_211;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_211:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_270;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_270:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_321;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_321:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_359;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_359:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_382;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_382:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_397;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_397:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_405;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_405:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 40;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 40;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 40;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 40;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 40;
			goto done;
			}
	St_212:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_271;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_271:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_322;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_322:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_360;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_360:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_383;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_383:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_398;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_398:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 43;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 43;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 43;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 43;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 43;
			goto done;
			}
	St_88:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 4){ /*  a-l n-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_151;}
		else if(c ==109) {			goto St_150;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_150:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_213;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_213:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 67;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 67;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 67;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 67;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 67;
			goto done;
			}
	St_151:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_214;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_214:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_272;}
		else if(c ==58) {		extcode = 88;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 88;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 88;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 88;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 88;
			goto done;
			}
	St_272:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 5){ /*  - b-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==97) {			goto St_323;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_323:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 6){ /*  - a-k m-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==108) {			goto St_361;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_361:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 7){ /*  - a-h j-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==105) {			goto St_384;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_384:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 5){ /*  - b-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==97) {			goto St_399;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_399:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 0){ /*  - a-r t-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==115) {			goto St_406;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_406:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 1){ /*  - a-d f-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==101) {			goto St_411;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_411:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 0){ /*  - a-r t-z */
			goto St_55;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else if(c ==115) {			goto St_413;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_413:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  - a-z */
			goto St_55;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 4){ /*  * / */
		extcode = 68;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 68;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==46) {		extcode = 68;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==43) {			goto St_11;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 68;
			goto done;
			}
	St_89:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 21;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 21;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 21;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 21;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 21;
			goto done;
			}
	St_90:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_152;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_152:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_215;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_215:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_273;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_273:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_324;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_324:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 12;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 12;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 12;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 12;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			goto done;
			}
	St_91:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 2){ /*  a-b d-g i-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_155;}
		else if(c ==104) {			goto St_154;}
		else if(c ==99) {			goto St_153;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_153:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_216;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_216:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_274;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_274:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_325;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_325:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_362;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_362:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 26;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 26;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 26;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 26;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 26;
			goto done;
			}
	St_154:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_217;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_217:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_275;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_275:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_326;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_326:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_363;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_363:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_385;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_385:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 8;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 8;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 8;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 8;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 8;
			goto done;
			}
	St_155:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_218;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_218:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_276;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_276:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_327;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_327:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_364;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_364:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_386;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_386:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_400;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_400:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 95;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 95;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 95;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_407;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 95;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 95;
			goto done;
			}
	St_407:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 105;
			goto done;
			}
	St_92:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 69;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 69;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 69;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 69;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 69;
			goto done;
			}
	St_93:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_156;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_156:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_219;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_219:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_277;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_277:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_328;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_328:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 96;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 96;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 96;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_365;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 96;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 96;
			goto done;
			}
	St_365:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 102;
			goto done;
			}
	St_94:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_157;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_157:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_220;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_220:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 70;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 70;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 70;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 70;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 70;
			goto done;
			}
	St_95:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 1){ /*  a-l n-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==109) {			goto St_158;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_158:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_221;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_221:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 71;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 71;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 71;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 71;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 71;
			goto done;
			}
	St_96:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_159;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_159:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_222;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_222:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 3){ /*  a-e g-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==102) {			goto St_278;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_278:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 1){ /*  a-x z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==121) {			goto St_329;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_329:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 72;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 72;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 72;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 72;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 72;
			goto done;
			}
	St_97:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_160;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_160:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 1){ /*  a-x z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==121) {			goto St_223;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_223:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_279;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_279:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 3){ /*  a-e g-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==102) {			goto St_330;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_330:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 73;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 73;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 73;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 73;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 73;
			goto done;
			}
	St_98:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 4){ /*  a-d f-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_162;}
		else if(c ==101) {			goto St_161;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_161:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_224;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_224:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 5){ /*  a-u w-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==118) {			goto St_280;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_280:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 6){ /*  a-y */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==122) {			goto St_331;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_331:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 5){ /*  a-u w-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==118) {			goto St_366;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_366:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_387;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_387:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 74;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 74;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 74;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 74;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 74;
			goto done;
			}
	St_162:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_225;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_225:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_281;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_281:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_332;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_332:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_367;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_367:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 75;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 75;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 75;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 75;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 75;
			goto done;
			}
	St_99:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_163;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_163:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_226;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_226:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_282;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_282:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 44;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 44;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 44;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 44;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 44;
			goto done;
			}
	St_100:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 7){ /*  a-b d-r u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_166;}
		else if(c ==115) {			goto St_165;}
		else if(c ==99) {			goto St_164;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_164:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 4){ /*  a-j l-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==107) {			goto St_227;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_227:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_283;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_283:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 7){ /*  a-f h-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==103) {			goto St_333;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_333:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_368;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_368:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 89;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 89;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 89;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 89;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 89;
			goto done;
			}
	St_165:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_228;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_228:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 76;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 76;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 76;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 76;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 76;
			goto done;
			}
	St_166:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2816] & 1<< 0){ /*  a-g i-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_230;}
		else if(c ==104) {			goto St_229;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_229:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 77;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 77;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 77;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 77;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 77;
			goto done;
			}
	St_230:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_284;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_284:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_334;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_334:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_369;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_369:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 78;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 78;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 78;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 78;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 78;
			goto done;
			}
	St_101:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_167;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_167:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_231;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_231:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_285;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_285:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_335;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_335:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_370;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_370:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 98;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 98;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 98;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_388;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 98;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 98;
			goto done;
			}
	St_388:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 103;
			goto done;
			}
	St_102:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_168;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_168:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_232;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_232:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_286;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_286:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_336;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_336:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_371;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_371:
		if((c= *p++) ==58) {			goto St_115;}
		else if(c ==47) {			goto St_389;}
		else {--p; goto fallback; }
	St_389:
		if((c= *p++) ==47) {			goto St_401;}
		else {--p; goto fallback; }
	St_401:
		if( scanTbl[(c= *p++)+2816] & 1<< 1){ /*  $ --: _ a-z */
			goto St_408;}
		else {--p; goto fallback; }
	St_408:
		/*  $ --: _ a-z*/
		while(scanTbl[(c= *p++)+2816] & 1<< 1);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 86;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_103:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2816] & 1<< 2){ /*  a-l n-o r-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==113) {			goto St_171;}
		else if(c ==112) {			goto St_170;}
		else if(c ==109) {			goto St_169;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_169:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_233;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_233:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_287;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_287:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_337;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_337:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 3){ /*  a-e g-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==102) {			goto St_372;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_372:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_390;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_390:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_402;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_402:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_409;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_409:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 90;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 90;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 90;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 90;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 90;
			goto done;
			}
	St_170:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_234;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_234:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_288;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_288:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_338;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_338:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_373;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_373:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 79;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 79;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 79;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 79;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 79;
			goto done;
			}
	St_171:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_235;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_235:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_289;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_289:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_339;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_339:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_374;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_374:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 80;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 80;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 80;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 80;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 80;
			goto done;
			}
	St_104:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_172;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_172:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_236;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_236:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_290;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_290:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+768] & 1<< 1){ /*  a-m o-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==110) {			goto St_340;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_340:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 7){ /*  a-f h-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==103) {			goto St_375;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_375:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 99;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 99;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 99;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_391;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 99;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 99;
			goto done;
			}
	St_391:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 104;
			goto done;
			}
	St_105:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2816] & 1<< 3){ /*  a-q s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_174;}
		else if(c ==114) {			goto St_173;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_173:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2560] & 1<< 5){ /*  a-u w-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==118) {			goto St_237;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_237:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_291;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_291:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_341;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_341:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_376;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_376:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 91;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 91;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 91;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 91;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 91;
			goto done;
			}
	St_174:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 46;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 46;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 46;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 46;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 46;
			goto done;
			}
	St_106:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_175;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_175:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_238;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_238:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_292;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_292:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 81;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 81;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 81;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 81;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 81;
			goto done;
			}
	St_107:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_176;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_176:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_239;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_239:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_293;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_293:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_342;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_342:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 82;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 82;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 82;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 82;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 82;
			goto done;
			}
	St_108:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 4){ /*  a-n p-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==111) {			goto St_177;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_177:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_240;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_240:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_294;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_294:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_343;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_343:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_377;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_377:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 100;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 100;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 100;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_392;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 100;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 100;
			goto done;
			}
	St_392:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 101;
			goto done;
			}
	St_109:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 2){ /*  a c-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==98) {			goto St_178;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_178:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1536] & 1<< 7){ /*  a-r t-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==115) {			goto St_241;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_241:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 3){ /*  a-b d-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==99) {			goto St_295;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_295:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_344;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_344:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 5){ /*  a-h j-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==105) {			goto St_378;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_378:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 2){ /*  a c-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==98) {			goto St_393;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_393:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_403;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_403:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 83;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 83;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 83;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 83;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 83;
			goto done;
			}
	St_110:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2304] & 1<< 0){ /*  a-q s-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==114) {			goto St_179;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_179:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 7){ /*  a-f h-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==103) {			goto St_242;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_242:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_296;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_296:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_345;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_345:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 84;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 84;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 84;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 84;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 84;
			goto done;
			}
	St_111:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 1){ /*  a-l n-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==109) {			goto St_180;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_180:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 6){ /*  a-o q-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==112) {			goto St_243;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_243:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 7){ /*  a-k m-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==108) {			goto St_297;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_297:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+512] & 1<< 5){ /*  b-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==97) {			goto St_346;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_346:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 1){ /*  a-s u-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==116) {			goto St_379;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_379:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_394;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_394:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 92;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 92;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 92;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 92;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 92;
			goto done;
			}
	St_112:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 5){ /*  a-t v-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==117) {			goto St_181;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_181:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+1792] & 1<< 0){ /*  a-d f-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==101) {			goto St_244;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_244:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if(c ==95) {			goto St_13;}
		else if(c ==61) {			goto St_54;}
		else if(c ==58) {		extcode = 6;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 6;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 6;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==44) {			goto St_298;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 6;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 6;
			goto done;
			}
	St_298:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  , = a-z */
			goto St_54;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 42;
			goto done;
			}
	St_113:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+2048] & 1<< 3){ /*  a-c e-z */
			goto St_69;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==100) {			goto St_182;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_53;}
		else if(c ==47) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_68;}
		else if(c ==46) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 13;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_182:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  a-z */
			goto St_69;}
		else if( scanTbl[c+256] & 1<< 0){ /*  A-Z */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  $ 0-9 */
			goto St_51;}
		else if( scanTbl[c+256] & 1<< 1){ /*  , = */
			goto St_54;}
		else if(c ==95) {			goto St_13;}
		else if(c ==58) {		extcode = 85;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_53;}
		else if(c ==47) {		extcode = 85;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_68;}
		else if(c ==46) {		extcode = 85;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_50;}
		else if(c ==45) {			goto St_55;}
		else if(c ==43) {			goto St_11;}
		else if(c ==42) {		extcode = 85;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_10;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 85;
			goto done;
			}
