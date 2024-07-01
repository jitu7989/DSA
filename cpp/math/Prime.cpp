bool check_prime(int x) {
    for (int i = 1; i * i <= x; ++i)
        if (!(x % i))
            return false;
    return true;
}
int main() {

}