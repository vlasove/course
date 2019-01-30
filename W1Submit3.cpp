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

                 for (size_t i=0; i<3; i++){   //листаем массив TaskInfo по ключам 
            if (!task_count)          //TaskStatus используя числовые
                break;                //значения этих ключей
                
            TaskStatus status=static_cast<TaskStatus>(i);
            TaskStatus next_status=static_cast<TaskStatus>(i+1);

            if (untouched.count(status) && task_count>=untouched[status]){
              
                updated [next_status]=untouched[status];
                task_count-=untouched[status];
                untouched.erase(status);

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
         return tie (updated, untouched);


        return tie(updated, untouched);

          

      }

private:
    map<string, TasksInfo> persons;
};