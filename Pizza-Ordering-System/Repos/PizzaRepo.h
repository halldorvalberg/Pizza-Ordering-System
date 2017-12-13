#ifndef PIZZAREPO_H
#define PIZZAREPO_H


class PizzaRepo
{
    public:
        PizzaRepo();
        virtual ~PizzaRepo();

        Pizza returnSelectedPizza(int pizza_number);

    protected:

    private:
};

#endif // PIZZAREPO_H
