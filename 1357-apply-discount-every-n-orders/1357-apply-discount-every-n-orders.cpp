class Cashier {
public:
    int count=0;
    int n=0;
    int d=0;
    unordered_map<int,int>price;
    Cashier(int nn, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<products.size();i++)
        {
            price[products[i]]=prices[i];
        }
        d=discount;
        n=nn;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double bill=0;
        for(int i=0;i<product.size();i++)
        {
            bill+=(price[product[i]])*amount[i];
        }
        if(count%n==0)
        {
            double dd=(100-d);
            dd/=100;
            bill=bill*dd;
        }
          return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */