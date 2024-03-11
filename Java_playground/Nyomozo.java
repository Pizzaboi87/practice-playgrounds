public class Nyomozo {
    public String nev;
    private String[] gyanusitottak;
    private int[] nyomok;

    /* Egy kétparaméteres konstruktor: a konstruktor csak a gyanúsítottak és a nyomok tömbjét várja, ebben a sorrendben, ezeket a paraméterek alapján beállítja. A nyomozó nevét "Columbo"-ra állítja be.*/

    public Nyomozo(String[] gyanusitottak, int[] nyomok) {
        this.nev = "Columbo";
        this.gyanusitottak = gyanusitottak;
        this.nyomok = nyomok;
    }

    /* Egy háromparaméteres konstruktor: a konstruktor a nyomozó nevét, a gyanúsítottak és a nyomok tömbjét várja, ebben a sorrendben, ezeket a paraméterek alapján beállítja */

    public Nyomozo(String nev, String[] gyanusitottak, int[] nyomok) {
        this.nev = nev;
        this.gyanusitottak = gyanusitottak;
        this.nyomok = nyomok;
    }

    /* Ahogy az ábrán is látható, a gyanúsítottak és a nyomok tömbje rendelkezzen publikus lekérdező és módosító metódusokkal, amelyek a teljes tömböt adják vissza, vagy állítják be */

    public String[] getGyanusitottak() {
        return gyanusitottak;
    }

    public void setGyanusitottak(String[] gyanusitottak) {
        this.gyanusitottak = gyanusitottak;
    }

    public int[] getNyomok() {
        return nyomok;
    }

    public void setNyomok(int[] nyomok) {
        this.nyomok = nyomok;
    }

    /* A nyomotFelhasznal metódusban a nyomozó felhasználja a kiválasztott sorszámú nyomot, azaz törli a nyomok tömbből a paraméterben kapott indexnek megfelelő elemet (amennyiben van ilyen indexű eleme). A törlés során fontos, hogy a tömb mérete változik. Ezt úgy tudjuk elérni, hogy egy teljesen új tömböt hozunk létre (ami pontosan egy elemmel kevesebbet tárol), és ebbe másoljuk át a tömb kívánt tartalmát. Ezután ne felejtsük el a nyomok tömböt erre az új tömbre állítani! A metódus true értékkel tér vissza, ha sikeres volt a törlés, false értékkel pedig ha nem volt a kapott indexű elem. */
    
    public boolean nyomotFelhasznal(int index) {
        if (index < 0 || index >= nyomok.length) {
            System.out.println("Nem létező nyom.");
            return false;
        }

        int[] ujNyomok = new int[nyomok.length - 1];

        System.out.println("Jelenlegi nyom felhasználva: " + nyomok[index]);

        for (int i = 0; i < index; i++) {
            ujNyomok[i] = nyomok[i];
        }

        for (int i = index; i < ujNyomok.length; i++) {
            ujNyomok[i] = nyomok[i + 1];
        }

        nyomok = ujNyomok;

        System.out.println("Megmaradt nyomok listája: " + java.util.Arrays.toString(nyomok) + "\n");
        return true;
    }

    /* A felmentoBizonyitek metódusban a nyomozó kizár egy gyanút az egyik gyanúsítottoról, azaz törli a gyanusitottak tömbből a paraméterben kapott név egyik előfordulását, amennyiben volt benne. A gyanúsítottak között egy név többször is előfordulhat, azaz lehet ismétlődés. Ilyen esetben a legutolsó előfordulást törli a metódus, de ekkor is csak egy elemet töröl. A törlés során fontos, hogy a tömb mérete változik. Ezt úgy tudjuk elérni, hogy egy teljesen új tömböt hozunk létre (ami pontosan egy elemmel kevesebbet tárol), és ebbe másolojuk át a tömb kívánt tartalmát. Ezután ne felejtsük el a gyanusitottak tömböt erre az új tömbre állítani! A metódus true értékkel tér vissza, ha sikeres volt a törlés, false értékkel pedig ha nem volt a kapott névnek megfelelő elem. */

    public boolean felmentoBizonyitek(String kit) {
        System.out.println("Felmentés: " + kit);

        int index = -1;

        for (int i = 0; i < gyanusitottak.length; i++) {
            if (gyanusitottak[i].equals(kit)) {
                index = i;
            }
        }

        if (index == -1) {
            System.out.println("Nem létező gyanúsított.");
            return false;
        }

        String[] ujGyanusitottak = new String[gyanusitottak.length - 1];

        for (int i = 0; i < index; i++) {
            ujGyanusitottak[i] = gyanusitottak[i];
        }

        for (int i = index; i < ujGyanusitottak.length; i++) {
            ujGyanusitottak[i] = gyanusitottak[i + 1];
        }

        gyanusitottak = ujGyanusitottak;

        System.out.println("Gyanúsított felmentve, gyanúsítottak átrendezve.");
        System.out.println("Gyanúsítottak listája: " + java.util.Arrays.toString(gyanusitottak) + "\n");
        return true;
    }

    /* Az inditek metódusban a jelenleg vizsgált gyanúsítottról új terhelő bizonyítékot talál a nyomozó, ezért a gyanusitottak tömb legelső elemét a tömb végére helyezi át. A művelet során a tömb mérete nem változik. */

    public void inditek() {
        System.out.println("Új indíték merült fel a gyanúsítottal szemben: " + gyanusitottak[0]);

        String elso = gyanusitottak[0];

        for (int i = 0; i < gyanusitottak.length - 1; i++) {
            gyanusitottak[i] = gyanusitottak[i + 1];
        }

        gyanusitottak[gyanusitottak.length - 1] = elso;

        System.out.println("GYanúsítás megtörtént, gyanúsítottak átrendezve.");
        System.out.println("Gyanúsítottak listája: " + java.util.Arrays.toString(gyanusitottak) + "\n");
    }

    /* A nyomokatRendez metódusban a nyomozó átértékeli a rendelkezésére álló nyomokat. Ennek során a metódus megfordítja a nyomok tömböt. A művelet során a tömb mérete nem változik. */

    public void nyomokatRendez() {
        System.out.println("Nyomok átrendezése...");

        int[] ujNyomok = new int[nyomok.length];

        for (int i = 0; i < nyomok.length; i++) {
            ujNyomok[i] = nyomok[nyomok.length - 1 - i];
        }

        nyomok = ujNyomok;
        System.out.println("Nyom felhasználva, nyomok átrendezve.");
        System.out.println("Nyomok listája: " + java.util.Arrays.toString(nyomok) + "\n");
    }

    /* Az alibikEliminalasa metódusban a nyomozó kizár egyes nyomokat. Ennek során a metódus törli a nyomok tömb minden harmadik elemét. Tehát a 2-es indexű elemtől kezdve hármasával lépkedve törli az elemeket. Ha eleve nem volt három eleme a tömbnek, akkor nem végez módosítást. A törlés során fontos, hogy a tömb mérete változik. Ezt úgy tudjuk elérni, hogy egy teljesen új tömböt hozunk létre (ami az új méretnek megfelelő számú elemet tárol), és ebbe másoljuk át a tömb kívánt tartalmát. Ezután ne felejtsük el a gyanusitottak tömböt erre az új tömbre állítani! */

    public void alibikEliminalasa() {
        System.out.println("Alibik eliminálása...");

        if (nyomok.length < 2) {
            System.out.println("Nincs elég nyom.");
            return;
        }

        int[] ujNyomok = new int[nyomok.length - nyomok.length / 3];

        for (int i = 0, j = 0; i < nyomok.length; i++) {
            if ((i + 1) % 3 != 0) {
                ujNyomok[j] = nyomok[i];
                j++;
            }
        }

        nyomok = ujNyomok;
        System.out.println("Nyomok átrendezve.");
        System.out.println("Nyomok listája: " + java.util.Arrays.toString(nyomok) + "\n");
    }

    /*  bajbanVan metódusban a nyomozó maga a vizsgált gyanúsított. Ilyenkor a metódus megkeresi a nyomok tömbben az első felmentő bizonyítékot (1-es értéket), ha van ilyen. Amennyiben van, a metódus törli ezt a bizonyítékot a nyomotFelhasznal metódus meghívásával, illetve ha ez sikeres, akkor felmenti a nyomozót a felmentoBizonyitek meghívásával a nyomozó saját nevére. Amennyiben sikeresen felmentette magát a nyomozó, akkor a metódus true értékkel tér vissza, egyébként false értéket ad. */

    public boolean bajbanVan() {
        System.out.println("A nyomozó bajban van...");
        for (int i = 0; i < nyomok.length; i++) {
            if (nyomok[i] == 1) {
                if (nyomotFelhasznal(i)) {
                    felmentoBizonyitek(nev);
                    return true;
                }
            }
        }

        return false;
    }

    /* A nyomozas metódus során a nyomozó elvégzi a nyomozást. Ennek során áttekinti a nyomokat egymás után, egyszerre mindig csak az aktuális nyommal, azaz a nyomok tömb legelső elemével foglalkozik, ezt az épp vizsgált gyanúsítottra kell értelmezni, azaz a gyanusitottak tömb legelső elemére. A nyomok számértékek, a következő eseteknek felelnek meg:
    
    • 1 - Felmentő bizonyítékot találtunk (felmentoBizonyitek)
    • 2 - Új indíték merült fel (inditek)
    • 3 - A nyomok rendezésre szorulnak (nyomokatRendez)
    • 4 - Ki kell zárni néhány nyomot (alibikEliminalasa)
    • 5 - Hamis nyom

    A nyomozás maga csak akkor indul el, ha legalább egy nyomunk, és legalább egy gyanúsítottunk van. Amennyiben nincs egy gyanúsított sem, a metódus a "Sajnos az ügy megoldatlan, nincs gyanúsított" szöveggel térjen vissza! Ha a nyomozás során bármikor elfogy a nyomunk, de több, mint egy gyanúsítottunk van még, akkor a metódus a "Nincs elég nyom, a megmaradt gyanúsítottak: [nevek]" szöveggel térjen vissza, ahol a [nevek] az összes megmaradt gyanúsított neve, szóközökkel elválasztva, a tömbben éppen elfoglalt sorrendjükben. Itt ügyeljünk rá, hogy az utolsó név után ne legyen szóköz, csak a nevek között! Amennyiben a nyomozás során bármikor csak egyetlen gyanúsítottunk marad (akkor is, ha van még nyom), a metódus térjen vissza a "Az ügy megoldva, a bűnös: [nev]" szöveggel, ahol a [nev] az egyetlen gyanúsított neve. A nyomozás során a nyomokon haladunk végig, amennyiben egy nyomot kivizsgálunk, azt rögtön ki is vesszük a tömbből a nyomotFelhasznal metódus felhasználásával. 1-es esetben a legelső gyanúsítottunkat felmentjük, a 2-4 esetekben meghívjuk az esetnek megfelelő metódust. 5-ös esetben a következő nyomunk hamis, azaz azt is törölnük kell a nyomok közül (amennyiben van következő), annak értéke nem fog kihatni a nyomozásra. Ha a nyomozás során bármikor a nyomozó maga kerülne a vizsgálat központjába, azaz a neve megegyezik a gyanusitottak tömb legelső elemével, akkor felhasznál egy felmentő bizonyítékot saját magának, amennyiben van ilyen. Ehhez hívjuk meg a bajbanVan metódust! */

    public String nyomozas() {
        String eredmeny = "";

        if (gyanusitottak.length == 0) {
            eredmeny = "Sajnos az ügy megoldatlan, nincs gyanúsított.";
        } else if(gyanusitottak.length == 1) {
            eredmeny = "Az ügy megoldva, a bűnös: " + gyanusitottak[0];
        }
        else {
            System.out.println("Nyomozás elkezdve...");
        
            for (int i = 0; i <= nyomok.length; i++) {

                if(gyanusitottak.length == 1) {
                    eredmeny = "Az ügy megoldva, a bűnös: " + gyanusitottak[0];
                }

                int vizsgaltNyom = nyomok[0];

                switch (vizsgaltNyom) {
                    case 1:
                        nyomotFelhasznal(0);
                        felmentoBizonyitek(gyanusitottak[0]);
                        i = 0;
                        break;
                    case 2:
                    nyomotFelhasznal(0);
                        if (gyanusitottak[0].equals(nev)) {
                            bajbanVan();
                            inditek();
                            i = 0;
                        } else {
                            inditek();
                            i = 0;
                        }
                        break;
                    case 3:
                        nyomotFelhasznal(0);
                        nyomokatRendez();
                        i = 0;
                        break;
                    case 4:
                        nyomotFelhasznal(0);
                        alibikEliminalasa();
                        i = 0;
                        break;
                    case 5:
                        nyomotFelhasznal(0);
                        System.out.println("Az előző nyom hamis volt, így a következő nyom is elveszett:");
                        nyomotFelhasznal(0);
                        i = 0;
                    break;
                }

                if (nyomok.length == 0 && gyanusitottak.length > 1) {
                    String nevek = "";
                    for (int j = 0; j < gyanusitottak.length; j++) {
                        nevek += gyanusitottak[j];
                        if (j < gyanusitottak.length - 1) {
                            nevek += " ";
                        }
                    }
                    eredmeny = "Nincs elég nyom, a megmaradt gyanúsítottak: " + nevek;
                }
            }
        }

        return eredmeny;
    }
}
