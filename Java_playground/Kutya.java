public class Kutya {
    public String nev;
    private String[] kedvencEtelek;
    private short ehseg;
    private long jokedv;

    public Kutya(String nev) {
        this.nev = nev;
        this.kedvencEtelek = new String[]{"csirke", "sajt", "lazac"};
    }

    public Kutya(String nev, String... kedvencEtelek) {
        this.nev = nev;
        this.kedvencEtelek = kedvencEtelek;
    }

    public boolean szereti(String etel) {
        for (String kedvencEtel : kedvencEtelek) {
            if (kedvencEtel.equalsIgnoreCase(etel)) {
                return true;
            }
        }
        return false;
    }

    public void ehesenNez() {
        ehseg++;
        System.out.println("Vau!");
    }

    public Kutya farokCsovalas() {
        jokedv++;
        return this;
    }

    public void eszik(String etel) {
        if (!szereti(etel)) {
            ehesenNez();
            return;
        }
        ehseg = (short) Math.max(0, ehseg - 1);
        if (ehseg == 0) {
            farokCsovalas();
        }
    }
    
    public boolean odajon(String nev) {
        if(this.nev.length() != nev.length()) {
            return false;
        } else {
            int diff = 0;
            for (int i = 0; i < this.nev.length(); i++) {
                if (this.nev.charAt(i) != nev.charAt(i)) {
                    diff++;
                }
            }
            if (diff > 2) {
                return false;
            } else {
                return true;
            }
        }
    }

    public static Kutya kutyaEtetes(Kutya elso, Kutya masodik, String etel) {
        if (elso.szereti(etel) && masodik.szereti(etel)) {
            double ke1 = Math.sqrt((elso.ehseg / (double)2) * (elso.jokedv / (double)3));
            double ke2 = Math.sqrt((masodik.ehseg / (double)2) * (masodik.jokedv / (double)3));
            if (ke1 == ke2) {
                return elso;
            }
            return ke1 > ke2 ? elso : masodik;
        }
        if (elso.szereti(etel)) {
            return elso;
        }
        if (masodik.szereti(etel)) {
            return masodik;
        }
        return null;
    }
}