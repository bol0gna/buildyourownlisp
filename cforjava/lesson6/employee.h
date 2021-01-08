/* definitions for Employee class */

typedef struct employee* Employee;

extern Employee new_Employee(const char* name, const int id);
extern void Employee_free(Employee this);

extern void Employee_print(const Employee this);
extern char* Employee_getName(const Employee this);
extern void Employee_setName(Employee this, char* name);
extern int Employee_getID(const Employee this);
extern void Employee_setID(Employee this, int id);
