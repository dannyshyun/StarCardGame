package myGame;

import java.util.Scanner;

public class GameUtil {

	public static void main(String[] args) {
//		æ“¾ŠpF??E?
//		int p = (int)Math.random()*5;
//		Object ch = CharSel(p);
		
//		á¢”v
		
		CardLoad cl = new CardLoad();
		cl.shuffle();
		String[] pubcard = cl.getScards();
		
//		for (String c : pubcard) {
//			System.out.println(c);
//		}
		cl.deal();
		
		System.out.println("p1“Iè”v");
		String[] p1cards = cl.getP1handcards();
		for (String c : p1cards) {
			System.out.print(c + " ");
		}
		
		System.out.println();
		
		String[] p2cards = cl.getP2handcards();
//		for (String c : p2cards) {
//			System.out.print(c + " ");
//		}
		
//		MoveTurn
//		o”v
		
//		—A“üo”v•À”»Ğ—A“ü?¥”Û‡–@
		String sel;
		do{Scanner input= new Scanner(System.in);
		System.out.println("select cards :");
		sel = input.next();
		}while(containRepeatChar(sel)||isStringInteger(sel,8)==false);
		
//		—A“ü•ûŒü
		String dir;
		do{Scanner input = new Scanner(System.in);
		System.out.println("select diraction :");
		dir = input.next();
		}while(dir.matches("[+-0]") == false);
		
		
//		›’è”v•ú“üo”v??E
		String [] selcard = new String[7];
		for(int i =0 ; i < sel.length() ; i++) {
			int c = Integer.parseInt(sel.substring(i, i+1));
			if(c == 0){break;}
			selcard[c-1] = p1cards [c-1];
			p1cards [c-1] = null;
		}
		
//		ŒvZˆÚ“®?
		System.out.println("Move turn o“I”v:");
		int p1move = 0;
		for ( String c : selcard) {
			System.out.print(c + " ");
//			System.out.println(c.substring(0, 4));
			if( c!=null && c.substring(0, 4).equals("Move")) {
//				System.out.println("z");
				p1move += Integer.parseInt(c.substring(5, 6));
			}
		}
		System.out.println();
		System.out.print("ˆÚ“®? :");
		if(dir.equals("0")) {
			System.out.println(p1move);
		}else 
		System.out.println(dir + p1move);
		System.out.println();
		System.out.println("p1™”éP“I”v");
		for ( String c : p1cards) {
			System.out.print(c + " ");
		}
		System.out.println();
//		pco”v
		String [] p2selcard = new String[7];
		int p2move = 0;
		for (int i = 0; i < p2cards.length; i++) {
			String c = p2cards[i];
			if(c.substring(0, 4).equals("Move")) {
				p2selcard[i] = c;
				p2cards[i] = null;
				p2move += Integer.parseInt(c.substring(5, 6));
				
			}else p2selcard[i] = null;
			
		}
//		pc•ûŒü
		String p2dir;
		if((int)(Math.random()*2)==0) {
			p2dir = "-";
		}else p2dir = "+";
		
		System.out.println();
		System.out.println("Move turn p2o“I”v:");
		System.out.println();
		for (String c : p2selcard) {
			System.out.print(c + " ");
		}
		System.out.println();
		System.out.print("ˆÚ“®?:");
		System.out.println(p2dir + p2move);
		System.out.println();
		System.out.println("------");
//		for (String c : p2cards) {
//			System.out.print(c + " ");
//		}
		System.out.println("p1™”éP“I”v");
		for ( String c : p1cards) {
			System.out.print(c + " ");
		}
		System.out.println();
		
		
//		”»’è‹—??E
		int dist = 1;
		switch(dir) { 
		case "+" : dist += p1move;break;
		case "-" : dist -= p1move;break;
		default : break;				
		}
		switch(p2dir) {
		case "+" : dist += p2move;break;
		case "-" : dist -= p2move;break;
		}
		System.out.println(dist);
		if(dist >= 2)dist = 2;
		else if(dist < 1)dist = 0;
		System.out.println();
		System.out.println("‹—??E "+dist);
		
//		”»’èæ??E
		

//		Šß‰ÆU?‰ñ‡		
//		—A“üo”v•À”»Ğ—A“ü?¥”Û‡–@
		String atksel;
		do{Scanner input= new Scanner(System.in);
		System.out.println("select Atk cards :");
		atksel = input.next();
		}while(containRepeatChar(atksel)||isStringInteger(atksel,8)==false);
		
//		›’è”v•ú“üo”v??E
		String [] atkselcard = new String[7];
		for(int i =0 ; i < atksel.length() ; i++) {
			int c = Integer.parseInt(atksel.substring(i, i+1));
			if(c == 0){break;}
			atkselcard[c-1] = p1cards [c-1];
			p1cards [c-1] = null;
		}
		
//		ŒvZU??
		int p1atk = 0;
		switch(dist) {
		case 0 : for ( String c : atkselcard) {
					System.out.print(c + " ");
		//			System.out.println(c.substring(0, 4));
					if( c!=null && c.substring(0, 5).equals("Sword")) {
		//				System.out.println("z");
						p1atk += Integer.parseInt(c.substring(6, 7));
					}
				}break;
		case 1,2:for ( String c : atkselcard) {
					System.out.print(c + " ");
		//			System.out.println(c.substring(0, 4));
					if( c!=null && c.substring(0, 3).equals("Gun")) {
		//				System.out.println("z");
						p1atk += Integer.parseInt(c.substring(4, 5));
					}
				}break;
		}
		
		
		System.out.println();
		System.out.println("Atk turn p1o“I”v:");
		System.out.println(p1atk);
		
//		
//		±??E

		String p1atkrs[] = new String[p1atk] ;
		int p1atks = 0;  //U?¬Œ÷?
		for(int i = 0; i < p1atk; i++) {
			
			int j = (int)(Math.random()*3);
			if(j == 0) {
				p1atkrs[i] = "o";
				p1atks += 1;
			}else p1atkrs[i] = "x";
		}
		System.out.println();
		System.out.println("p1U? : ");
		for (String c: p1atkrs){
			System.out.print(c+" ");
			}
		System.out.println();
		System.out.println("¬Œ÷ŠQ : ");
		System.out.println(p1atks);
		
		
//		“däI–hç‰ñ‡
//		pc–hço”v
		String [] p2defselcard = new String[7];
		int p2def = 0;
		for (int i = 0; i < p2cards.length; i++) {
			String c = p2cards[i];
			if(c!=null && c.substring(0, 2).equals("Sh")) {
				p2defselcard[i] = c;
				p2cards[i] = null;
				p2def += Integer.parseInt(c.substring(7, 8));
				
			}else p2defselcard[i] = null;
		}
		System.out.println("p2–hç : ");	
		for(String c:p2defselcard){
			
			System.out.print(c + " ");
		}
		System.out.println();
		System.out.println(p2def);
//		“däI–h‹š±??E
		
		String p2defrs[] = new String[p2def] ;
		int p2defs = 0;
		for(int i = 0; i < p2def; i++) {
			
			int j = (int)(Math.random()*3);
			if(j == 0) {
				p2defrs[i] = "o";
				p2defs += 1;
			}else p2defrs[i] = "x";
		}
		System.out.println();
		System.out.println("¬Œ÷–hç : ");
		for (String c: p2defrs){
			System.out.print(c+" ");
			}
		System.out.println();
		System.out.println(p2defs);
		
//		Šß‰Æ–hç‰ñ‡
//		—A“üo”v•À”»Ğ—A“ü?¥”Û‡–@
		String defsel;
		do{Scanner input= new Scanner(System.in);
		System.out.println("select Def cards :");
		defsel = input.next();
		}while(containRepeatChar(defsel)||isStringInteger(defsel,8)==false);
		
//		›’è”v•ú“üo”v??E
		String [] defselcard = new String[7];
		for(int i =0 ; i < defsel.length() ; i++) {
			int c = Integer.parseInt(defsel.substring(i, i+1));
			if(c == 0){break;}
			defselcard[c-1] = p1cards [c-1];
			p1cards [c-1] = null;
		}
//		ŒvZ–hç?
		int p1def = 0;
		for ( String c : defselcard) {
					System.out.print(c + " ");
					if( c!=null && c.substring(0, 2).equals("Sh")) {
						p1def += Integer.parseInt(c.substring(7, 8));
					}
		}
		System.out.println();
		System.out.println(p1def);

//		±??E

		String p1defrs[] = new String[p1def] ;
		int p1defs = 0;  //U?¬Œ÷?
		for(int i = 0; i < p1def; i++) {
			
			int j = (int)(Math.random()*3);
			if(j == 0) {
				p1defrs[i] = "o";
				p1defs += 1;
			}else p1defrs[i] = "x";
		}
		System.out.println();
		System.out.println("p1–hç : ");
		for (String c: p1defrs){
			System.out.print(c+" ");
			}
		System.out.println();
		System.out.println("¬Œ÷–hç : ");
		System.out.println(p1defs);

//		“däI–hç‰ñ‡
//		pc–hço”v
		String [] p2atkselcard = new String[7];
		int p2atk = 0;
		switch(dist) {
		case 0 :for (int i = 0; i < p2cards.length; i++) {
					String c = p2cards[i];
					if(c!=null && c.substring(0, 2).equals("Sw")) {
						p2atkselcard[i] = c;
						p2cards[i] = null;
						p2atk += Integer.parseInt(c.substring(6, 7));
						
					}else p2atkselcard[i] = null;
				}break;
		case 1,2:for (int i = 0; i < p2cards.length; i++) {
					String c = p2cards[i];
					if(c!=null && c.substring(0, 2).equals("Gu")) {
						p2atkselcard[i] = c;
						p2cards[i] = null;
						p2atk += Integer.parseInt(c.substring(4, 5));						
					}else p2atkselcard[i] = null;
				}break;
		}

		System.out.println("p2U? : ");	
		for(String c:p2atkselcard){
			
			System.out.print(c + " ");
		}
		System.out.println();
		System.out.println(p2atk);
//		“däIU?±??E
		
		String p2atkrs[] = new String[p2atk] ;
		int p2atks = 0;
		for(int i = 0; i < p2atk; i++) {
			
			int j = (int)(Math.random()*3);
			if(j == 0) {
				p2atkrs[i] = "o";
				p2atks += 1;
			}else p2atkrs[i] = "x";
		}
		System.out.println();
		System.out.println("¬Œ÷U? : ");
		for (String c: p2atkrs){
			System.out.print(c+" ");
			}
		System.out.println();
		System.out.println(p2atks);

		
//		String[?] p1selcard = p1cards[?];
//		p1cards[?] = null;

	}
	public static boolean containRepeatChar(String str){
		  if(str==null||str.isEmpty()){
		   return false;
		  }
		  char[] elements=str.toCharArray(); 
		  for(char e:elements){
		   if(str.indexOf(e)!=str.lastIndexOf(e)){
		    return true;
		   }
		  }
		  return false;
		 }
	public static boolean isStringInteger(String stringToCheck, int radix) {
        if(stringToCheck.isEmpty()) return false;           //Check if the string is empty
        for(int i = 0; i < stringToCheck.length(); i++) {
            if(i == 0 && stringToCheck.charAt(i) == '-') {     //Check for negative Integers
                if(stringToCheck.length() == 1) return false;
                else continue;
            }
            if(Character.digit(stringToCheck.charAt(i),radix) < 0) return false;
        }
        return true;
    }

}
//private static Object CharSel(int p) {
//		switch(p) {
//		case 0: new Bulbasaur(); 
//		}
//}