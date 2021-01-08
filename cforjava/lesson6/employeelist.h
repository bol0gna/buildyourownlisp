/* LinkedList class for holding only Employee objects */

typedef struct elist* EmployeeList;
extern EmployeeList new_EmployeeList();
extern void EmployeeList_prepend(EmployeeList this, Employee val);
extern void EmployeeList_append(EmployeeList this, Employee val);

extern int EmployeeList_length(EmployeeList this);
extern Employee EmployeeList_first(EmployeeList this);
extern Employee EmployeeList_last(EmployeeList this);
extern void EmployeeList_print(EmployeeList this);
