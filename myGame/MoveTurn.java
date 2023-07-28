package myGame;

public class MoveTurn {
		public MoveTurn() {
			
		}
//		MoveTurn
//		o”v
		

		

		
		
//		›’è”v•ú“üo”v??E
		String [] selcard = new String[7];
		public String[] getSelcard() {
			return selcard;
		}

		public MoveTurn(String sel, String[]p1cards) {
			for(int i =0 ; i < sel.length() ; i++) {
				int c = Integer.parseInt(sel.substring(i, i+1));
				if(c == 0){break;}
				selcard[c-1] = p1cards [c-1];
				p1cards [c-1] = null;
			}
		}
		
//		ŒvZˆÚ“®?






		private int p1move = 0;
		for ( String c : selcard) {
			System.out.print(c + " ");
//			System.out.println(c.substring(0, 4));
			if( c!=null && c.substring(0, 4).equals("Move")) {
//				System.out.println("z");
				p1move += Integer.parseInt(c.substring(5, 6));
			}
		}

		if(dir.equals("0")) {
			System.out.println(p1move);
		}else 
		System.out.println(dir + p1move);
		System.out.println();
		System.out.println("--------");
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
		for (String c : p2selcard) {
			System.out.print(c + " ");
		}
		System.out.println();
		System.out.println("------");
		for (String c : p2cards) {
			System.out.print(c + " ");
		}
		System.out.println();
		System.out.println(p2dir + p2move);
		
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
		
		System.out.println(dist);

}
}
