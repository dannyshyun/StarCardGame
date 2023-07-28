package myGame;

public class Bulbasaur {
		public Bulbasaur() {
			
		}
		
		public int hp = 9;
		public int atk = 9;
		public int def = 13;
		public void vinewhip() {
			atk += 5;				
		}
		
		public void growth() {			
			if(hp == 8) {
				hp += 1;
			}else if (hp == 7) {
				hp += 2;
			}
			hp += 3;
		}
		public void razorleaf() {
			atk += 8;
		}
		public int sleeppowder() {
			return 0;
		}
	

}
