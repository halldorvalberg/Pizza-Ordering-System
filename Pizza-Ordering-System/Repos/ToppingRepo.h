#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H


class ToppingRepo
{
    public:
        ToppingRepo();
        virtual ~ToppingRepo();

        vector<Toppings> getToppingsToVector();

    protected:

    private:
};

#endif // TOPPINGREPO_H
