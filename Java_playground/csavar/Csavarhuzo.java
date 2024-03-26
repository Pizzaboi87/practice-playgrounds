public class Csavarhuzo {
    private int meret;
    private Csavarfej fej;

    public Csavarhuzo(int meret, Csavarfej fej) {
        this.meret = meret;
        this.fej = fej;
    }

    public int getMeret() {
        return meret;
    }

    public Csavarfej getCsavarfej() {
        return fej;
    }

    public void setMeret(int meret) {
        this.meret = meret;
    }

    public void setCsavarfej(Csavarfej fej) {
        this.fej = fej;
    }

    public String toString() {
        switch(this.fej) {
            case EGYHORNYU:
            return "hagyomanyos feju csavarhuzo";
            case PHILLIPS:
            return "csillagfeju csavarhuzo";
            case IMBUSZ:
            return "imbuszfeju csavarhuzo";
            default:
            return "nem ismert feju csavarhuzo";
        }
    }
}
