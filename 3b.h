#ifndef LAB3_3_INTCLASS_H
#define LAB3_3_INTCLASS_H

#include <iostream>

namespace ns {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::bad_alloc;

    class set {
    private:
        static const int max_length = 10;
        int length{};
        int data[max_length]{};
    public:
        explicit set() : length(0) {};
        explicit set(int);
        explicit set(int, const int *);

        set &intersection(set &) const;
        int is_in_set(int);

        friend std::ostream &operator<<(std::ostream &, const set &);
        friend std::istream &operator>>(std::istream &, set &);
        set &operator+(set &);
        set &operator+=(int);
        set &operator-(set &);
    };

    template <class T>
    int enter (T &a, const char *what) {
        cout << what << endl;
        cin >> a;
        if (!cin.good()) {
            cout << "Error with cin \n Try again" << endl;
            return 1;
        } else
            return 0;
    }
}

#endif //LAB3_3_INTCLASS_H
