public class KovetelmenySzamito {
    public static String teljesites(double rop1, double rop2, double rop3, double rop4, double zh, int hazi) {
        double pontszam = rop1 + rop2 + rop3 + rop4 + zh;
        String eredmeny = "";

        if(pontszam >= 50 && hazi >= 1) {
            eredmeny = "sikeres";
        } else {
            eredmeny = "sikertelen";
        }

        return eredmeny;
    }
}