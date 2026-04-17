bool isInteger(double x) {
    return abs(x - floor(x)) < eps;
}