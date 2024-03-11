import java.util.Scanner;

/**
 * Ebben a feladatban egy egyszerű kis játékot kell implementálni. A játékban két lehetőség van, vagy időt kell átkonvertálni óra:perc:másodperc
 * formátumra, vagy össze kell adni egy szám számjegyeinek az összegét. 
 *
 * A játék elején a program main metódusában a felhasználó által adott 1-es vagy 2-es opciókkal kiválasztja, melyik feladatot akarja megoldani. 
 * Az 1 jelölje az idő átváltást, a 2-es pedig a számjegyek összeadását. 
 * 
 * Az időkonvertálás során a felhasználónak meg kell adnia egy időtartamot, amit másodpercben kell érteni. 
 * Ezt kell átalakítani óra:perc:másodperc formátumra. Figyelem, a rossz inputokat külön kezelni kell!!!
 * 
 * A számjegyek összegzésekor a felhasználótől bekért nemnegatív egész érték számjegyeit kell összegezni. 
 *
 * Bár a BIRO nem nézi a main metódusodat, mielőtt a kódod feltöltöd, próbáld azt ki. Sokszor segítség lehet, hogy Javaban minden osztály külön futtatható, ha az megfelelően van implementálva.
*/
public class SimpleGame {

	/**
	 * Írj egy metódust, ami egy másodpercben adott időt átkonvertál óra:perc:másodperc alakra
	 * @param seconds a másodperc, amit át szeretnénk konvertálni
	 * @return string az átalakított időpont a következő formátumban: 23:59:59
	 * 
	 * Példák: 
	 * - Ha a bemenet 1432, akkor írd ki és térj vissza a következő értékkel: 0:23:52
	 * - Ha a bemenet 0, akkor írd ki és térj vissza a következő értékkel: 0:0:0
	 * - Ha a bemenet nem érvényes (azaz negatív), akkor írd ki és térj vissza a következő értékkel: -1:-1:-1.  
	 */
	public String convertTime(int seconds){
		String convertedTime = "";
		if(seconds == 0) {
			convertedTime = "0:0:0";
		} else if(seconds < 0) {
			convertedTime = "-1:-1:-1";
		} else {
			int hours = seconds / 3600;
			int minutes = (seconds % 3600) / 60;
			int sec = seconds % 60;
			convertedTime = hours + ":" + minutes + ":" + sec;
		}
		return convertedTime;
	}

	/**
	 * Írj egy metódust, ami összeadja egy nemnegatív szám számjegyeit.
	 * @param integer, aminek a számjegyeit össze szeretnénk adni.
	 * @return integer a paraméterben kapott egész számjegyeinek az összege
	 * 
	 * Példák: 
	 * - Ha a bemenet 565, akkor írd ki és térj vissza 16-tal.
	 * - Ha a bemenet 7, akkor írd ki és térj vissza 7-tel.
	 * - Ha a bemenet 0, akkor írd ki és térj vissza 0-val.
	 */
	public int digitsSum(int input){
		input = Math.abs(input);
		int sum = 0;

		while(input > 0) {
			sum += input % 10;
			input /= 10;
		}
		return sum;
	}
	
	public static void main(String[] args) {
		// Hozz létre egy példányt a SimpleGame osztályból.
		SimpleGame game = new SimpleGame();
		
		// Kérdezd meg a felhasználót, melyik játékkal akar játszani.
		// Majd kérd be az adott feladatnak megfelelő inputot.

		Scanner scanner = new Scanner(System.in);
		System.out.println("Melyik játékkal szeretnél játszani? (1: idő átváltás, 2: számjegyek összegezése)");

		if(scanner.hasNextInt()) {
			int gameType = scanner.nextInt();
			if(gameType == 1) {
				System.out.println("Kérlek add meg a másodperceket!");
				if(scanner.hasNextInt()) {
					int seconds = scanner.nextInt();
					System.out.println(game.convertTime(seconds));
				} else {
					System.out.println("Nem számot adtál meg!");
					scanner.close();
					return;
				}
			} else if(gameType == 2) {
				System.out.println("Kérlek add meg a számot!");
				if(scanner.hasNextInt()) {
					int number = scanner.nextInt();
					System.out.println(game.digitsSum(number));
				} else {
					System.out.println("Nem megfelelő szám!");
					scanner.close();
					return;
				}
			} else {
				System.out.println("Nincs ilyen játék!");
				scanner.close();
				return;
			}
		} else {
			System.out.println("Nem számot adtál meg!");
			scanner.close();
			return;
		}

		scanner.close();
		
		
		// Ha a felhasználó az 1-et választotta, akkor kérj tőle egy egész értéket, amire meghívod a SimpleGame objektumon keresztül a convertTime metódust.
		// Ha a felhasználó a 2-öt választotta, akkor kérj tőle egy egész értéket, amire meghívod a SimpleGame objektumon keresztül a digitsSum metódust.
	}	
}