public class Complex {
    private final double real;
    private final double imag;

    public Complex() {
        this(0, 0);
    }

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public String toString() {
        if (imag == 0) {
            return real + "";
        }
        if (real == 0) {
            return imag + "i";
        }
        if (imag < 0) {
            return real + "-" + (-imag) + "i";
        }
        return real + "+" + imag + "i";
    }

    public Complex add(Complex other) {
        return new Complex(real + other.real, imag + other.imag);
    }

    public Complex mul(Complex other) {
        return new Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    public Complex conjugate() {
        return new Complex(real, -imag);
    }
}
