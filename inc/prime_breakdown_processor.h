#include <map>
#include <string>
#include <vector>

struct amazon_item {
    std::string id;
    std::string name;
    std::string shipping_name;
    double subtotal_tax;
    double subtotal;
    double total;
};

struct amazon_refund {
    std::string id;
};

/**
 * @brief 
 * 
 */
class PrimeBreakdownProcessor {
    
    public:
    PrimeBreakdownProcessor();
    ~PrimeBreakdownProcessor();

    /**
     * @brief add amazon items to the processor as a csv file from amazon.com
     * 
     * @param filename (csv file)
     */
    void addItems(const char* filename);

    /**
     * @brief add amazon items to the processor
     * 
     * @param items 
     */
    void addItems(std::vector<amazon_item> items);
    
    /**
     * @brief add amazon returns to the processor as a csv file from amazon.com
     * 
     * @param filename (csv file)
     */
    void addRefunds(const char* filename);

    /**
     * @brief add amazon returns to the processor
     * 
     * @param returns 
     */
    void addRefunds(std::vector<amazon_refund> refunds);

    /**
     * @brief create report
     * 
     * @return std::map<std::string, double> 
     */
    std::map<std::string, double> processReport();


    private:
    std::vector<amazon_item> amazon_items;
    std::vector<amazon_refund> amazon_refunds;
};

