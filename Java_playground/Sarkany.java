public class Sarkany {
    int eletero;
    boolean ehes;

    public Sarkany() {
        this(100, true);
    }

    public Sarkany(int eletero, boolean ehes) {
        setEletero(eletero);
        setEhes(ehes);
    }

    public int getEletero() {
        return eletero;
    }

    public boolean isEhes() {
        return ehes;
    }

    public void setEletero(int eletero) {
        if (eletero < 0) {
            System.err.printf("megolted a sarkanyt\n");
            this.eletero = 0;
        } else {
            this.eletero = eletero;
        }
    }

    public void setEhes(boolean ehes) {
        if(eletero < 50) {
            this.ehes = true;
        } else {
            this.ehes = ehes;
        }
    }

    public String toString() {
        return String.format("A sarkany eletereje %d, es jelenleg %s ehes.", eletero, ehes ? "rettenetesen" : "veletlenul nem");
    }

    public boolean vajonElMeg() {
        return eletero > 0 ? true : false;
    }

    public void eszik(int x) {
        if(x > 0) {
            eletero += x;
        } else {
            System.err.printf("en a helyedben nem eheztetnek egy sarkanyt\n");
        }
    }

    public int harcol(int[] ellenfelek) {
        int holtEllenfelek = 0;

        if(ehes) {
            for(int i = 0; i < ellenfelek.length; i++) {
                eletero -= ellenfelek[i] / 2;
                if(eletero <= 0) {
                    return holtEllenfelek;
                }
                holtEllenfelek++;
            }
            ehes = false;
            return holtEllenfelek;
        } else {
            return 0;
        }
    }
}
