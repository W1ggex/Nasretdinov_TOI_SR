#include <string>
#include <iostream>
using namespace std;

//legacy functions
bool is_integer(string console) {  
    int start = 0; 
    if (console.size() == 0) 
        return false; 
    if (console[0] == '-') 
        start = 1; 
    if (console[start] == '0' && console.size() > 1)  
        return false;
    for (int i = start; i < console.size(); i++) 
        if (!isdigit(console[i])) 
            return false;
    
    if (console.size() - start > 9) 
        return false;
   
    return true;
}

bool is_double(string console) {  
    int start = 0;
    bool has_dot = false;
    if (console.size() == 0)
        return false;
    if (console[0] == '-') 
        start = 1;  
    if (console[start] == '0' && console.size() > 1) 
        return false;
    for (int i = start; i < console.size(); i++) { 
        if (!isdigit(console[i]) && console[i] != '.')   
            return false;
        if (console[i] == '.') {
            if (has_dot)
                return false;
            else
                has_dot = true;
        }
    }
    
    if (console.size() - start > 9) 
        return false;
    return true;
}

int get_integer(string msg, bool must_be_positive) { 
    cout << msg << endl;  
    bool input_is_correct; 
    string console;  
    int r = -1; 
    do {
        cin >> console;  
        input_is_correct = is_integer(console);  
        if (!input_is_correct) 
            cout << "Enter a proper number\n";
        else {
            r = stoi(console);
            if (r < 1 && must_be_positive && input_is_correct) {  
                input_is_correct = false; 
                cout << "Enter a natural number\n";
            }
        }
    } while (!input_is_correct); 
    return r;  
}

double get_double(string msg, bool must_be_positive) { 
    cout << msg;  
    bool input_is_correct; 
    string console;  
    double r = -1.0;  
    do {
        cin >> console;  
        input_is_correct = is_double(console);  
        if (!input_is_correct) 
            cout << "Enter a proper number\n";
        else {
            r = stod(console); 
            if (r < 1 && must_be_positive && input_is_correct) {  
                input_is_correct = false; 
                cout << "Enter a positive number\n";
            }
        }
    } while (!input_is_correct); 
    return r;  
}

string get_string(string msg) {
    cout << msg << endl;
    string console;
    cin >> console;
    return console;
}

//STRUCTURES
struct Timber {
public:
    string id;
    int depth_mm;
    int width_mm;
    int length_mm;
    string product_type;
    string wood_type;
    int m3_price;
    int m2_price;
    string in_stock_at;

    int volume;

    Timber* link_to_the_left;
    Timber* link_to_the_right;

    Timber(string id,
        int depth_mm,
        int width_mm,
        int length_mm,
        string product_type,
        string wood_type,
        int m3_price,
        int m2_price,
        string in_stock_at)
    {
        this->id = id;
        this->depth_mm = depth_mm;
        this->width_mm = width_mm;
        this->length_mm = length_mm;
        this->product_type = product_type;
        this->wood_type = wood_type;
        this->m3_price = m3_price;
        this->m2_price = m2_price;
        this->in_stock_at = in_stock_at;
    }

    Timber() {

    };

    Timber(string msg) {
        Timber product;
        this->id = get_string("Enter timber id:");
        this->depth_mm = get_integer("Enter timber depth:", true);
        this->width_mm = get_integer("Enter timber width:", true);
        this->length_mm = get_integer("Enter timber length:", true);
        this->product_type = get_string("Enter the product type:");
        this->wood_type = get_string("Enter the wood type:");
        this->m3_price = get_integer("Enter the cubic meter price, -1 if not applicable:", false);
        if (this->m3_price == -1)
            this->m2_price = get_integer("Enter the square meter price:", true);
        else
            this->m2_price = -1;
        this->in_stock_at = get_string("Enter where the timber is in stock at");
    }

    void PrintGoodInfo()
    {
        cout << "Article: " << id << " Depth: " << depth_mm << " Width: " << width_mm << " Length: " << length_mm << " Product type: " << product_type << " Wood type: " << wood_type << " Price: ";
        if (m3_price != -1)
            cout << m3_price << " per medium^3";
        else
            cout << m2_price << "per medium^2";
        cout << " In stock at: " << in_stock_at << endl;
    }

    string GetArticle() {
        return id;
    }

    void SetArticle(string id) {
        this->id = id;
    }

    int GetWidth() {
        return width_mm;
    }

    void SetWidth(int width) {
        this->width_mm = width_mm;
    }

    int GetDepth() {
        return depth_mm;
    }

    void SetDepth(int width) {
        this->depth_mm = depth_mm;
    }

    int GetLength() {
        return length_mm;
    }

    void SetLength(int length_mm) {
        this->length_mm = length_mm;
    }

    string GetWoodType() {
        return wood_type;
    }

    void SetWoodType(string wood_type) {
        this->wood_type = wood_type;
    }

    string GetProductType() {
        return product_type;
    }

    void SetProductType(string product_type) {
        this->product_type = product_type;
    }

    int GetM3Price() {
        return m3_price;
    }

    void SetM3Price(int m3_price) {
        this->m3_price = m3_price;
    }

    int GetM2Price() {
        return m2_price;
    }

    void SetM2Price(int m2_price) {
        this->m2_price = m2_price;
    }

    string GetInTimberListAt() {
        return in_stock_at;
    }

    void SetInTimberListAt(string in_stock_at) {
        this->in_stock_at = in_stock_at;
    }

};

//task 1 structures
struct ArrayItem {
    string str;  //either a wood or a product type
    int index;
};

struct ArrayIndexator {
    ArrayItem* items;
    int size;
    int capacity;
};

struct ArrayController { //keeps the array and indexators together
    Timber* stock;
    int size;
    int capacity;
    ArrayIndexator wood_type_indexator, product_type_indexator;
};

//task 2 structures
struct TreeNode {
    string str;
    int index;
    TreeNode* left;
    TreeNode* right;
};

struct TreeIndexator {  //points to the tree root
    TreeNode* root;
};

struct TreeController {   //keeps the array and trees together
    TreeIndexator product_type_indexator;
    TreeIndexator wood_type_indexator;
    Timber* stock;
    int size;
    int capacity;
};

struct CallbackData {  //allows to link the tree with the functions
    const TreeController& tree;
    void (*callback)(const Timber&);
};

//task 3 strutures
struct TimberNode {
    Timber data;
    TimberNode* next;
};

struct TimberList {
    TimberNode* head;
};

void print_timber_info(const Timber& item)
{
    cout << "Article: " << item.id << " Depth: " << item.depth_mm << " Width: " << item.width_mm << " Length: " << item.length_mm << " Product type: " << item.product_type << " Wood type: " << item.wood_type << " Price: ";
    if (item.m3_price != -1)
        cout << item.m3_price << " per medium^3";
    else
        cout << item.m2_price << "per medium^2";
    cout << " In stock at: " << item.in_stock_at << endl;
}


//TASK 1 FUNCTIONS
void destroy_array_indexator(ArrayIndexator& index) {
    if (index.items) {
        delete[] index.items;
        index.items = nullptr;
    }
    index.capacity = index.size = 0;
}

void create_array_indexator(ArrayIndexator& index, int capacity) {
    index.capacity = capacity;
    index.items = new ArrayItem[capacity];
    index.size = 0;
}

void array_indexator_append(ArrayIndexator& indexator, const string& s, int position) {
    if (indexator.size >= indexator.capacity) {
        ArrayItem* temp = new ArrayItem[indexator.capacity * 2];
        for (int j = 0; j < indexator.size; ++j) temp[j] = indexator.items[j];
        delete[] indexator.items;
        indexator.items = temp;
        indexator.capacity *= 2;
    }
    int i = indexator.size - 1;
    while (i >= 0 && indexator.items[i].str > s) {
        indexator.items[i + 1] = indexator.items[i];
        --i;
    }
    indexator.items[i + 1] = { s, position };
    ++indexator.size;
}

void array_update_indexes(ArrayController& arrayController) {
    arrayController.product_type_indexator.size = 0;
    arrayController.wood_type_indexator.size = 0;
    for (int j = 0; j < arrayController.size; ++j) {
        array_indexator_append(arrayController.product_type_indexator, arrayController.stock[j].product_type, j);
        array_indexator_append(arrayController.wood_type_indexator, arrayController.stock[j].wood_type, j);
    }
}

void array_remove_position(ArrayController& arrayController, int position) {
    for (int j = position; j < arrayController.size - 1; ++j) arrayController.stock[j] = arrayController.stock[j + 1];
    --arrayController.size;
    array_update_indexes(arrayController);
}

void array_print_by_product_type(const ArrayController& arrayController) {
    for (int j = 0; j < arrayController.product_type_indexator.size; ++j)
        print_timber_info(arrayController.stock[arrayController.product_type_indexator.items[j].index]);
}

void array_print_by_wood_type(const ArrayController& arrayController) {
    for (int j = 0; j < arrayController.wood_type_indexator.size; ++j)
        print_timber_info(arrayController.stock[arrayController.wood_type_indexator.items[j].index]);
}

void array_init(ArrayController& arrayController, int capacity) {
    arrayController.capacity = capacity;
    arrayController.size = 0;
    arrayController.stock = new Timber[capacity];
    create_array_indexator(arrayController.product_type_indexator, capacity);
    create_array_indexator(arrayController.wood_type_indexator, capacity);
}

void array_destroy(ArrayController& arrayController) {
    destroy_array_indexator(arrayController.product_type_indexator);
    destroy_array_indexator(arrayController.wood_type_indexator);
    delete[] arrayController.stock;
    arrayController.stock = nullptr;
    arrayController.size = arrayController.capacity = 0;
}

int array_indexator_search_iterative(const ArrayIndexator& indexator, const string& s) {
    int low = 0, high = indexator.size - 1;
    while (low <= high) {
        int medium = low + (high - low) / 2;
        if (indexator.items[medium].str == s) return medium;
        indexator.items[medium].str < s ? low = medium + 1 : high = medium - 1;
    }
    return -1;
}

int array_indexator_recursive_search(const ArrayIndexator& indexator, const string& s, int left, int right) {
    if (left > right) return -1;
    int medium = left + (right - left) / 2;
    if (indexator.items[medium].str == s) return medium;
    return indexator.items[medium].str < s
        ? array_indexator_recursive_search(indexator, s, medium + 1, right)
        : array_indexator_recursive_search(indexator, s, left, medium - 1);
}

int array_indexator_search_recursive_caller(const ArrayIndexator& indexator, const string& s) {
    return array_indexator_recursive_search(indexator, s, 0, indexator.size - 1);
}

int array_indexator_find_iterative(const ArrayIndexator& indexator, const string& s) {
    int res = array_indexator_search_iterative(indexator, s);
    return res != -1 ? indexator.items[res].index : -1;
}

int array_indexator_find_recursive(const ArrayIndexator& indexator, const string& s) {
    int res = array_indexator_search_recursive_caller(indexator, s);
    return res != -1 ? indexator.items[res].index : -1;
}

int array_find_by_product_type(const ArrayController& arrayController, const string& s) {
    return array_indexator_find_iterative(arrayController.product_type_indexator, s);
}

int array_find_by_wood_type(const ArrayController& arrayController, const string& s) {
    return array_indexator_find_recursive(arrayController.wood_type_indexator, s);
}

bool array_append(ArrayController& arrayController, Timber item) {
    if (array_find_by_wood_type(arrayController, (&item)->wood_type) != -1 || array_find_by_product_type(arrayController, (&item)->product_type) != -1) return false;
    if (arrayController.size == arrayController.capacity) {
        Timber* temp = new Timber[arrayController.capacity * 2];
        for (int j = 0; j < arrayController.size; ++j) temp[j] = arrayController.stock[j];
        delete[] arrayController.stock;
        arrayController.stock = temp;
        arrayController.capacity *= 2;
    }
    arrayController.stock[arrayController.size] = item;
    array_indexator_append(arrayController.product_type_indexator, item.product_type, arrayController.size);
    array_indexator_append(arrayController.wood_type_indexator, item.wood_type, arrayController.size);
    ++arrayController.size;
    return true;
}

bool array_edit(ArrayController& arrayController, int position, Timber item) {
    if ((array_find_by_product_type(arrayController, item.product_type) != -1 && array_find_by_product_type(arrayController, (&item)->product_type) != position) ||
        (array_find_by_wood_type(arrayController, item.wood_type) != -1 && array_find_by_wood_type(arrayController, (&item)->wood_type) != position)) return false;
    arrayController.stock[position] = item;
    array_update_indexes(arrayController);
    return true;
}

Timber array_return_by_index(const ArrayController& arrayController, int position) {
    return arrayController.stock[position];
}


//TASK 2 FUNCTIONS
void init_tree_indexator(TreeIndexator& index) {
    index.root = nullptr;
}

void destroy_tree_indexator_helper(TreeNode* node) {
    if (node == nullptr) return;
    destroy_tree_indexator_helper(node->left);
    destroy_tree_indexator_helper(node->right);
    delete node;
}

void destroy_tree_indexator(TreeIndexator& index) {
    destroy_tree_indexator_helper(index.root);
    index.root = nullptr;
}

void tree_indexator_add(TreeIndexator& index, const string& str, int indexator) {
    TreeNode* newNode = new TreeNode;
    newNode->str = str;
    newNode->index = indexator;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (index.root == nullptr) {
        index.root = newNode;
        return;
    }

    TreeNode* current = index.root;
    while (true) {
        if (str < current->str) {
            if (current->left == nullptr) {
                current->left = newNode;
                break;
            }
            else {
                current = current->left;
            }
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                break;
            }
            else {
                current = current->right;
            }
        }
    }
}

void tree_indexator_bypass(const TreeNode* node, void (*callback)(const string&, int, void*), void* userdata) {
    //allows to make a left to right bypass of the tree 
    if (node == nullptr) return;
    tree_indexator_bypass(node->left, callback, userdata);
    callback(node->str, node->index, userdata);
    tree_indexator_bypass(node->right, callback, userdata);
}

void tree_indexator_bypass_caller(const TreeIndexator& index, void (*callback)(const string&, int, void*), void* userdata) {
    tree_indexator_bypass(index.root, callback, userdata);
}

void tree_init(TreeController& treeController, int capacity) {
    treeController.capacity = capacity;
    treeController.size = 0;
    treeController.stock = new Timber[capacity];
    init_tree_indexator(treeController.product_type_indexator);
    init_tree_indexator(treeController.wood_type_indexator);
}

void tree_destroy(TreeController& treeController) {
    delete[] treeController.stock;
    destroy_tree_indexator(treeController.product_type_indexator);
    destroy_tree_indexator(treeController.wood_type_indexator);
}

void index_bypass(const string& str, int index, void* userData) {
    //allows to bypass the tree index
    CallbackData* userdata = (CallbackData*)userData;
    userdata->callback(userdata->tree.stock[index]);
}

void tree_print_by_wood_type(const TreeController& treeController, void (*callback)(const Timber&)) {
    CallbackData userdata = { treeController, callback };
    tree_indexator_bypass_caller(treeController.wood_type_indexator, index_bypass, &userdata);
}

void tree_print_by_product_type(const TreeController& treeController, void (*callback)(const Timber&)) {
    CallbackData userdata = { treeController, callback };
    tree_indexator_bypass_caller(treeController.product_type_indexator, index_bypass, &userdata);
}

void tree_remove(TreeController& treeController, int indexator) {
    for (int i = indexator; i < treeController.size - 1; ++i) {
        treeController.stock[i] = treeController.stock[i + 1];
    }
    treeController.size--;
    
    //relink the tree nodes
    destroy_tree_indexator(treeController.product_type_indexator);
    destroy_tree_indexator(treeController.wood_type_indexator);
    init_tree_indexator(treeController.product_type_indexator);
    init_tree_indexator(treeController.wood_type_indexator);

    for (int i = 0; i < treeController.size; ++i) {
        tree_indexator_add(treeController.product_type_indexator, treeController.stock[i].product_type, i);
        tree_indexator_add(treeController.wood_type_indexator, treeController.stock[i].wood_type, i);
    }
}

int tree_indexator_find_iterative(const TreeIndexator& index, const string& str) {
    const TreeNode* current = index.root;
    while (current) {
        if (current->str == str) return current->index;
        current = str > current->str ? current->right : current->left;
    }
    return -1;
}

int tree_indexator_find_recursive(const TreeNode* node, const string& str) {
    if (node == nullptr) return -1;
    if (str == node->str) return node->index;
    if (str < node->str) return tree_indexator_find_recursive(node->left, str);
    return tree_indexator_find_recursive(node->right, str);
}

int tree_indexator_find_recursive_caller(const TreeIndexator& index, const string& str) {
    return tree_indexator_find_recursive(index.root, str);
}

int tree_find_by_product_type(const TreeController& treeController, const string& product_type) {
    return tree_indexator_find_iterative(treeController.product_type_indexator, product_type);
}

int tree_find_by_wood_type(const TreeController& treeController, const string& wood_type) {
    return tree_indexator_find_recursive_caller(treeController.wood_type_indexator, wood_type);
}

bool tree_append(TreeController& treeController, Timber stock) {
    if (tree_find_by_product_type(treeController, stock.product_type) != -1 ||
        tree_find_by_wood_type(treeController, stock.wood_type) != -1) {
        return false;
    }
    if (treeController.size >= treeController.capacity) {
        int newCapacity = treeController.capacity * 2;
        Timber* newData = new Timber[newCapacity];
        for (int i = 0; i < treeController.size; ++i) {
            newData[i] = treeController.stock[i];
        }
        delete[] treeController.stock;
        treeController.stock = newData;
        treeController.capacity = newCapacity;
    }

    treeController.stock[treeController.size] = stock;
    tree_indexator_add(treeController.product_type_indexator, stock.product_type, treeController.size);
    tree_indexator_add(treeController.wood_type_indexator, stock.wood_type, treeController.size);
    treeController.size++;
    return true;
}

const Timber tree_return_by_index(const TreeController& treeController, int indexator) {
    return treeController.stock[indexator];
}


//TASK 3 FUNCTIONS
void list_destroy(TimberList& list) {
    TimberNode* current = list.head;
    while (current) {
        TimberNode* temp = current;
        current = current->next;
        delete temp;
    }
    list.head = nullptr;
}

void list_init(TimberList& list) {
    list.head = nullptr;
}

void array_search_print(ArrayController& arrayController, int (*searchFunc)(ArrayController&)) {
    int index = searchFunc(arrayController);
    if (index == -1) cout << "Not found\n";
    else print_timber_info(array_return_by_index(arrayController, index));
}

void array_delete_the_search(ArrayController& arrayController, int (*searchFunc)(ArrayController&)) {
    int index = searchFunc(arrayController);
    if (index == -1) cout << "Not found\n";
    else {
        array_remove_position(arrayController, index);
        cout << "Timber was successfully deleted\n";
    }
}

void array_edit_by_search(ArrayController& arrayController, int (*searchFunc)(ArrayController&)) {
    int index = searchFunc(arrayController);
    if (index == -1) cout << "Not found\n";
    else {
        Timber item = Timber("Input timber properties");
        bool isEdited = array_edit(arrayController, index, item);
        if (isEdited)
            cout << "The array was updated\n";
        else
            cout << "Record cannot be updated.\nProduct and wood types must be unique\n";
    }
}

void array_add_timber(ArrayController& arrayController) {
    Timber item = Timber("Input timber properties");
    bool isAdded = array_append(arrayController, item);
    if (isAdded)
        cout << "Timber was added\n";
    else
        cout << "Record cannot be added.\nProduct and wood types must be unique\n";
}

void fill_array(ArrayController& arrayController) {
    Timber* stock = new Timber[6]();
    stock[0] = { "pi10", 25, 100, 6000, "Plank", "Coniferous", 18300, -1, "Gari"};
    stock[1] ={ "l15sq", 150, 150, 6000, "Log", "Pine", 18300, -1, "Bobki" };
    stock[2] = { "sl50sq", 50, 50, 3000, "Small log", "Spruce", 12000, -1, "Bobki" };
    stock[3] = { "dp22sq", 22, 22, 1300, "Dowel", "Birch", 47610, -1, "Gari" };
    stock[4] = {"fp", 36, 136, 3000, "Floor plank", "Larch", 16340, -1, "Dobryanka"};
    stock[5] = { "os", 12, 1250, 2500, "OSB-3 Board", "Sawdust", 25867, -1, "Bobki" };
    
    for (int i = 0; i < 6; i++) array_append(arrayController, stock[i]);
}

void list_print(const TimberList& list) {
    for (TimberNode* ptr = list.head; ptr != nullptr; ptr = ptr->next) {
        print_timber_info(ptr->data);
    }
}

void tree_search(const TreeController& tree, int (*searchFunc)(const TreeController&)) {
    int index = searchFunc(tree);
    if (index == -1) {
        cout << "Not found\n";
        return;
    }
    print_timber_info(tree_return_by_index(tree, index));
}

void tree_delete_the_search(TreeController& tree, int (*searchFunc)(const TreeController&)) {
    int index = searchFunc(tree);
    if (index == -1) {
        cout << "Not found\n";
        return;
    }
    tree_remove(tree, index);
    cout << "Timber was successfully deleted\n";
}

void tree_add_timber(TreeController& tree) {
    Timber newTimber = Timber("Enter the timber properties:");
    bool isAdded = tree_append(tree, newTimber);
    if (isAdded)
        cout << "Timber was added\n";
    else
        cout << "Record cannot be added.\nProduct and wood types must be unique\n";
}

void fill_tree(TreeController& tree) {
    Timber* stock = new Timber[6]();
    stock[0] = { "pi10", 25, 100, 6000, "Plank", "Coniferous", 18300, -1, "Gari"};
    stock[1] ={ "l15sq", 150, 150, 6000, "Log", "Pine", 18300, -1, "Bobki" };
    stock[2] = { "sl50sq", 50, 50, 3000, "Small log", "Spruce", 12000, -1, "Bobki" };
    stock[3] = { "dp22sq", 22, 22, 1300, "Dowel", "Birch", 47610, -1, "Gari" };
    stock[4] = {"fp", 36, 136, 3000, "Floor plank", "Larch", 16340, -1, "Dobryanka"};
    stock[5] = { "os", 12, 1250, 2500, "OSB-3 Board", "Sawdust", 25867, -1, "Bobki" };
    
    for (int i = 0; i < 6; ++i) {
        tree_append(tree, stock[i]);
    }
}

void list_search(const TimberList& list, const Timber* (*searchFn)(const TimberList&)) {
    const Timber* item = searchFn(list);
    if (!item) {
        cout << "Not found\n";
        return;
    }
    print_timber_info(*item);
}

int array_search_wood_type(ArrayController& arrayController) {
    string value;
    cout << "Enter the wood type: ";
    cin >> value;
    return array_find_by_wood_type(arrayController, value);
}

int array_search_product_type(ArrayController& arrayController) {
    string value;
    cout << "Enter the product type: ";
    cin >> value;
    return array_find_by_product_type(arrayController, value);
}

int tree_search_by_wood_type(const TreeController& tree) {
    string value = get_string("Enter the wood type");
    return tree_find_by_wood_type(tree, value);
}

int tree_search_by_product_type(const TreeController& tree) {
    string value = get_string("Enter the product type");
    return tree_find_by_product_type(tree, value);
}

bool list_remove_by_product_type(TimberList *list, const string& product_type) {
    TimberNode** ptr = &list->head;
    while (*ptr) {
        if ((*ptr)->data.product_type == product_type) {
            TimberNode* temp = *ptr;
            *ptr = (*ptr)->next;  //relink to the next element
            delete temp;
            return true;
        }
        ptr = &((*ptr)->next);
    }
    //search was unsuccessful
    return false;
}

bool list_remove_by_wood_type(TimberList *list, const string& wood_type) {
    TimberNode** ptr = &list->head;
    while (*ptr) {
        if ((*ptr)->data.wood_type == wood_type) {
            TimberNode* temp = *ptr;
            *ptr = (*ptr)->next;
            delete temp;
            return true;
        }
        ptr = &((*ptr)->next);
    }
    return false;
}

bool list_append(TimberList& list, const Timber& item){
    const TimberNode* current = list.head;
    while (current) {
        if (current->data.product_type == item.product_type || current->data.wood_type == item.wood_type) {
            return false;
        }
        current = current->next;
    }

    TimberNode** insertPos = &list.head;
    while (*insertPos &&
        ((*insertPos)->data.product_type < item.product_type ||
            ((*insertPos)->data.product_type == item.product_type && (*insertPos)->data.wood_type < item.wood_type))) {
        insertPos = &((*insertPos)->next);
            }
    *insertPos = new TimberNode{ (item), *insertPos };
    return true;
} 

const Timber* list_product_type_search_iterative(const TimberList *list, const string& product_type) {
    TimberNode* ptr = list->head;
    while (ptr) {
        if (ptr->data.product_type == product_type)
            return &ptr->data;
        ptr = ptr->next;
    }
    return nullptr;
}

const Timber* list_search_by_wood_type_helper(const TimberNode* node, const string& wood_type) {
    if (!node) return nullptr;
    return node->data.wood_type == wood_type ? &node->data : list_search_by_wood_type_helper(node->next, wood_type);
}

const Timber* list_wood_type_search_recursive(const TimberList *list, const string& wood_type) {
    return list_search_by_wood_type_helper(list->head, wood_type);
}

const Timber* list_search_by_wood_type(const TimberList& list) {
    string wood_type;
    cout << "Enter the wood type: ";
    cin >> wood_type;
    return list_wood_type_search_recursive(&list, wood_type);
}

const Timber* list_search_by_product_type(const TimberList& list) {
    string product_type;
    cout << "Enter the product type: ";
    cin >> product_type;
    return list_product_type_search_iterative(&list, product_type);
}

void list_delete_by_product_type(TimberList& list) {
    string product_type;
    cout << "Enter the product type: ";
    cin >> product_type;
    bool isSuccesful = list_remove_by_product_type(&list, product_type);
    if (!isSuccesful) {
        cout << "Not found\n";
        return;
    }
    cout << "Timber was deleted succesfully\n";
}

void list_delete_by_wood_type(TimberList& list) {
    string wood_type;
    cout << "Enter the wood type: ";
    cin >> wood_type;
    bool isSuccesful = list_remove_by_wood_type(&list, wood_type);
    if (!isSuccesful) {
        cout << "Not found\n";
        return;
    }
    cout << "Timber was deleted succesfully\n";
}

void fill_list(TimberList& list)
{
    Timber* stock = new Timber[6]();
    stock[0] = { "pi10", 25, 100, 6000, "Plank", "Coniferous", 18300, -1, "Gari"};
    stock[1] ={ "l15sq", 150, 150, 6000, "Log", "Pine", 18300, -1, "Bobki" };
    stock[2] = { "sl50sq", 50, 50, 3000, "Small log", "Spruce", 12000, -1, "Bobki" };
    stock[3] = { "dp22sq", 22, 22, 1300, "Dowel", "Birch", 47610, -1, "Gari" };
    stock[4] = {"fp", 36, 136, 3000, "Floor plank", "Larch", 16340, -1, "Dobryanka"};
    stock[5] = { "os", 12, 1250, 2500, "OSB-3 Board", "Sawdust", 25867, -1, "Bobki" };
    for (int i = 0; i < 6; ++i)
    {
        list_append(list, stock[i]);
    }
}

void list_add_timber(TimberList& list) {
    Timber item = Timber("Input timber properties");
    bool isAdded = list_append(list, item);
    if (isAdded)
        cout << "Timber was added\n";
    else
        cout << "Record cannot be added.\nProduct and wood types must be unique\n";
}


int main()
{
    char taskNumber = '1';
    while (taskNumber != '0')
    {
        cout << "Choose the task number 1-3 or 4 to exit:" << endl;
        cin >> taskNumber;
        switch (taskNumber) {
        case'1': {
                ArrayController arrayController;
                array_init(arrayController, 20);
                fill_array(arrayController);
                char option = '1';
                while (option != '0')
                {
                    cout << "Choose the option:\n" << "1 - Back\n" << "2 - Add timber to the array\n"
                    << "3 - Print by the wood type\n" << "4 - Print by the product type\n"
                    << "5 - Search by the wood type\n" << "6 - Search by the product type\n"
                    << "7 - Edit by the wood type\n" << "8 - Edit by the product type\n"
                    << "9 - Delete by the wood type\n" << "0 - Delete by the product type\n";
                    cin >> option;
                    switch (option)
                    {
                    case'1':{ //back
                                option = '0';
                            }
                            break;
                            case'2': {
                                array_add_timber(arrayController);
                            }
                        break;
                            case'3': {
                                array_print_by_wood_type(arrayController);
                            }
                        break;
                            case'4': {
                                array_print_by_product_type(arrayController);
                            }
                        break;
                            case'5': {
                                array_search_print(arrayController, array_search_wood_type);
                            }
                        break;
                            case'6': {
                                array_search_print(arrayController, array_search_product_type);
                            }
                        break;
                            case'7': {
                                array_edit_by_search(arrayController, array_search_wood_type);
                            }
                        break;
                            case'8': {
                                array_edit_by_search(arrayController, array_search_product_type);
                            }
                        break;
                            case'9': {
                                array_delete_the_search(arrayController, array_search_wood_type);
                            }
                        break;
                            case'0': {
                                array_delete_the_search(arrayController, array_search_product_type);
                            }
                        break;
                        }
                    }
                    array_destroy(arrayController);  //to avoid mixing the links
                }
            break;
        case'2':
            {
                TreeController tree;
                tree_init(tree, 10);
                fill_tree(tree);
                char option = '1';
                while (option != '0') {
                    cout << "Choose the option:\n" << "1 - Back\n" << "2 - Add timber to the tree\n"
                    << "3 - Print by the wood type\n" << "4 - Print by the product type\n"
                    << "5 - Search by the wood type\n" << "6 - Search by the product type\n"
                    << "7 - Delete by the wood type\n" << "8 - Delete by the product type\n";
                    cin >> option;
                    switch (option) {
                    case'1': {
                            option = '0';
                    }
                        break;
                    case'2': {
                            tree_add_timber(tree);
                    }
                        break;
                    case'3':  {
                            tree_print_by_wood_type(tree, print_timber_info);
                    }
                        break;
                    case'4': {
                           tree_print_by_product_type(tree, print_timber_info);
                    }
                        break;
                    case'5': {
                            tree_search(tree, tree_search_by_wood_type);
                    }
                        break;
                    case'6':  {
                            tree_search(tree, tree_search_by_product_type);
                    }
                        break;
                    case'7':  {
                            tree_delete_the_search(tree, tree_search_by_wood_type);
                    }
                        break;
                    case'8':{
                            tree_delete_the_search(tree, tree_search_by_product_type);
                    }
                        break;

                    }
                }
                tree_destroy(tree);
            }
            break;
        case'3': {
                TimberList list;
                list_init(list);
                fill_list(list);
                
                char option = '1';
                while (option != '0') {
                    cout << "Choose the option:\n" << "1 - Back\n" << "2 - Add timber to the list\n"
                    << "3 - Print the list\n" << "4 - Search by the wood type\n"
                    << "5 - Search by the product type\n" << "6 - Delete by the product type\n"
                    << "7 - Delete by the wood type\n";
                    cin >> option;
                    switch (option)
                    {
                    case '1': { //back
                            option = '0';
                    }
                        break;
                    case '2':  {
                            list_add_timber(list);
                    }
                        break;
                    case '3':  {
                            list_print(list);
                    }
                        break;
                    case '4':  {
                            const Timber* item = list_search_by_wood_type(list);
                            if (!item) 
                                cout << "Not found\n";
                            else
                            print_timber_info(*item);
                    }
                        break;
                    case '5': {
                            const Timber* item = list_search_by_product_type(list);
                            if (!item) 
                                cout << "Not found\n";
                            else
                                print_timber_info(*item);
                    }
                    case '6': {
                            list_delete_by_wood_type(list);
                    }
                        break;
                    case '7':  {
                            list_delete_by_product_type(list);
                    }
                        break;
                    }
        

                }
                list_destroy(list);
        }
            break;
        case'4': {
                exit(0);
                 }
        }
    }
    return 0;
}