package myGame;

public class CardLoad {
		
		public CardLoad() {
			
		}
		private String Scards[] = new String[52];
		
		public String[] getScards() {
			return Scards;
		}
		private String p1handcards[] = new String [7];
		
		private String p2handcards[] = new String [7];
		
		public String[] getP1handcards() {
			return p1handcards;
		}




		public void setP1handcards(String[] p1handcards) {
			this.p1handcards = p1handcards;
		}




		public String[] getP2handcards() {
			return p2handcards;
		}




		public void setP2handcards(String[] p2handcards) {
			this.p2handcards = p2handcards;
		}
		




		//	êÙîv
		public void shuffle() {
			int nums = 52;
			int[] cards = new int [52];
			for(int i=0; i<cards.length; i++) {
				cards[i] = i;
			}
			// cards[0] = 0; => cards[1] = 1; => cards[2] = 2; =>.....

			int value = 0;
			String suit = null;
			
			for(int i=0; i<nums; i++) {
				int rand = (int)(Math.random()*(nums-i)+i);
				// 0~52 => 1~52 => 2~52 => ......

				int temp = cards[i]; 
				cards[i] = cards[rand];
				cards[rand] = temp;
				// ex: rand = 7; => [7, 1, 2, 3, 4, 5, 6, 0, 8.....]

				if(cards[i]<36) {
					switch(cards[i]%3) {
					case 0: value = 1;break;
					case 1: value = 2;break;
					case 2: value = 3;break;
					}
					switch(cards[i]/12) {
					case 0: suit = "Sword";break;
					case 1: suit = "Gun";break;
					case 2: suit = "Shield";break;
					}
				}else {
					switch(cards[i]%2) {
					case 0:	value = 1;break;
					case 1: value = 2;break;
					}
					switch((cards[i]-36)/8) {
					case 0:	suit = "Move";break;
					case 1: suit = "Star";break;
					}
				}
				// Sword1*4, Sword2*4, Sword3*4, Gun1*4....... => card*36
				// Move1*4, Move2*4, Star1*4...... => card*16

				StringBuffer l = new StringBuffer();
				StringBuffer j = l.append(suit).append("?").append(value);
				this.Scards[i] = j.toString();
				// ex: Move?2
			}
		}
		
	
		

		for(int card : cards){
				System.out.println(card);
		}
		for(String Scard : Scards) {
				System.out.print(Scard + " ");
		}
		System.out.println();
		System.out.println("------");
			
//		·¢îv
		public void deal() {
		int cardslimit = 7;
		int p1cards = 0;
		int p2cards = 0;
		
		for(int i=0 ; i<((cardslimit-p1cards)+ (cardslimit-p2cards)) ; i++) {
			
			if(i%2 == 0) {p1handcards[p1cards+(int)(i/2)] = Scards [i]; }
			
			else p2handcards[p1cards+(int)(i/2)] = Scards [i]; 
			
			
		}
		for ( String card : pcards1) {
			
			System.out.println(card);
	}
		
		
		System.out.println("------");
		for ( String card : pcards2) {
			
				System.out.println(card);
		}
		
		
		
		


}
}

