vector<double> solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        // linear case: bx + c = 0
        if (b == 0) return {};  // no solution
        return { -c / b };
    }

    double d = b*b - 4*a*c; // discriminant

    if (d < 0) return {}; // no real roots

    if (d == 0) {
        return { -b / (2*a) }; // one root
    }

    double sqrt_d = sqrt(d);
    double x1 = (-b + sqrt_d) / (2*a);
    double x2 = (-b - sqrt_d) / (2*a);
    vector<double> roots={x1,x2};
    sort(roots.begin(),roots.end());
    return roots;
}