#include <iostream>
#include <tuple>
#include <vector>
#include <map>

using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person){
      return persons[person];
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){

      ++persons[person][TaskStatus::NEW];

  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count){

          TasksInfo updated, untouched;


         //if (persons[person][TaskStatus::NEW] +persons[person][TaskStatus::IN_PROGRESS] + persons[person][TaskStatus::TESTING] > task_count ){
         //     task_count = persons[person][TaskStatus::NEW] +persons[person][TaskStatus::IN_PROGRESS] + persons[person][TaskStatus::TESTING] ;
         // }

         if(persons.count(person) == 0){
             return tie(updated, untouched);
         }else{
             untouched = persons[person];
         }

        untouched.erase(TaskStatus::DONE);
        TasksInfo to_erase;
        

            for (size_t i=0; i<3; i++){   //листаем массив TaskInfo по ключам 
            if (!task_count)          //TaskStatus используя числовые
                break;                //значения этих ключей
                
            TaskStatus status=static_cast<TaskStatus>(i);
            TaskStatus next_status=static_cast<TaskStatus>(i+1);

            if (untouched.count(status) && task_count>=untouched[status]){
              
                updated [next_status]=untouched[status];
                task_count-=untouched[status];
                to_erase[status] = untouched[status];
                //untouched.erase(status);

                persons[person][status] = 0;
                persons[person][next_status]+=updated [next_status];
            }
            else if (untouched.count(status) && task_count<untouched[status]){
              
                updated [next_status]=task_count;
                untouched [status]-=task_count;

                persons[person][status]-=task_count;
                persons[person][next_status]+=updated [next_status];

                break;
            }
         }

         TasksInfo new_untouched;
         for(size_t i  = 0; i < 3; i++){
             TaskStatus check_status=static_cast<TaskStatus>(i);

             if(to_erase.count(check_status) == 0){
                new_untouched[check_status] = untouched[check_status];
             }
         }
         
         return tie (updated, new_untouched);



          

      }

private:
    map<string, TasksInfo> persons;
};



void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main(){
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;
  
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
    
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);


    return 0;
}