public class Bokor {
    private String fajta;
    private int forma;
    private double suruseg;
    SovenyvagoOllo ollo;

    public Bokor(String fajta, double suruseg) {
        this.fajta = fajta;

        if(suruseg >= 0.0 && suruseg <= 100.0) {
            this.suruseg = suruseg;
        } else if (suruseg < 0) {
            this.suruseg = 0.0;
        } else {
            this.suruseg = 100.0;
        }
    }

    public void nyiras(SovenyvagoOllo ollo) {
        if(ollo.vag(this.suruseg)) {
            this.forma = 2;
        }
    }

    public void setSuruseg(double ujSuruseg) {
        if(ujSuruseg >= 0.0 && ujSuruseg <= 100.0) {
            this.suruseg = ujSuruseg;
        } else if (suruseg < 0) {
            this.suruseg = 0.0;
        } else {
            this.suruseg = 100.0;
        }
    }

    public String forma() {
        String bokorForma = "";

        switch (this.forma) {
            case 0:
                bokorForma = "cserje";
                break;
            case 1:
                bokorForma = "bokor";
                break;
            case 2:
                bokorForma = "formara nyirt";
                break;
            case 3:
                bokorForma = "kisse elburjanzott";
                break;
            case 4:
                bokorForma = "teljesen elburjanzott";
                break;
        }
        return bokorForma;
    }

    public double getSuruseg() {
        return this.suruseg;
    }

    public void novekedes() {
        if(this.forma < 4 && this.forma >= 0) {
            this.forma++;
        }
    }

    public String getFajta() {
        String bokorFajta = "";

        switch (this.fajta) {
            case "cserje":
                bokorFajta = "a bokor még csak cserje";
                break;
            case "bokor":
                bokorFajta = "a bokor egy normál, kicsi bokor";
                break;
            case "formara nyirt":
                bokorFajta = "formára nyírt bokor";
                break;
            case "kisse elburjanzott":
                bokorFajta = "a bokor kezd elburjánzani";
                break;
            case "teljesen elburjanzott":
                bokorFajta = "teljesen elburjánzott formájú bokor";
                break;
        }
        return bokorFajta;
    }

    public void setForma(int ujForma) {
        if(ujForma >= 0 && ujForma <= 4) {
            this.forma = ujForma;
        }
    }

    public void setFajta(String ujFajta) {
            if(ujFajta.equals("cserje") || ujFajta.equals("bokor") || ujFajta.equals("formara nyirt") || ujFajta.equals("kisse elburjanzott") || ujFajta.equals("teljesen elburjanzott")) {
                this.fajta = ujFajta;
            } else {
                this.fajta = "bokor";
                System.out.println("Nem megfelelő fajta, a bokor alapértelmezett fajtára lett állítva.");
            }
    }
}
