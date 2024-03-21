public class CserelhetoFejuCsavarhuzo extends Csavarhuzo{
    private int fejMeret;
    private boolean egyhornyuFej = true;
    private boolean phillipsFej = true;
    private boolean imbuszFej = true;

    public CserelhetoFejuCsavarhuzo(int meret, int fejMeret, Csavarfej csavarfej) {
        super(meret, csavarfej);
        this.fejMeret = fejMeret;
    }

    public int getMeret() {
        return super.getMeret() - this.fejMeret;
    }

    public void fejElhagy(String melyik) {
        switch (melyik) {
            case "egyhornyu":
                egyhornyuFej = false;
                break;
            case "phillips":
                phillipsFej = false;
                break;
            case "imbusz":
                imbuszFej = false;
                break;
            default:
                break;
        }
    }

    public boolean fejCsere(String melyikre) {
        String csavarFejString = getCsavarfej().toString().toLowerCase();

        if(csavarFejString.equals(melyikre)) {
            return false;
        } else if((melyikre.equals("egyhornyu") && !egyhornyuFej) || (melyikre.equals("phillips") && !phillipsFej) || (melyikre.equals("imbusz") && !imbuszFej)) {
            return false;
        } else {
            switch (melyikre) {
                case "egyhornyu":
                    setCsavarfej(Csavarfej.EGYHORNYU);
                    break;
                case "phillips":
                    setCsavarfej(Csavarfej.PHILLIPS);
                    break;
                case "imbusz":
                    setCsavarfej(Csavarfej.IMBUSZ);
                    break;
                default:
                    return false;
            }
            return true;
        }
    }
}
