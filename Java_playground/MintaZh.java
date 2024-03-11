public class MintaZh1 {
    
    public static String atalakit(String szoveg) {
        if (szoveg == null) {
            return null;
        }

        String ujSzoveg = "";
        for (int i = 0; i < szoveg.length(); i++) {
            if (szoveg.charAt(i) == 'e') {
                ujSzoveg += 'a';
            } else {
                ujSzoveg += szoveg.charAt(i);
            }
        }

        return ujSzoveg;
    }

    public static int tuzijatek(int[] tavolsagok, int latotav) {
        if (tavolsagok == null || tavolsagok.length == 0) {
            return -1;
        }
        
        int legjobbVarosIndex = -1;
        int maxLathatoVarosokSzama = 0;

        for (int i = 0; i < tavolsagok.length; i++) {
            int lathatoVarosokSzama = 2;
            if (i > 0) {
                if (tavolsagok[i - 1] <= latotav) {
                    lathatoVarosokSzama++;
                }
            }
            if (i < tavolsagok.length - 1) {
                if (tavolsagok[i] <= latotav) {
                    lathatoVarosokSzama++;
                }
            }

            if (lathatoVarosokSzama > maxLathatoVarosokSzama) {
                maxLathatoVarosokSzama = lathatoVarosokSzama;
                legjobbVarosIndex = i;
            }
        }

        return legjobbVarosIndex;
    }
}
