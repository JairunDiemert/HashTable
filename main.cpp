
#include <iostream>
#include <string>
using namespace std;

int hash(std::string key, int tableSize){
  unsigned long hashVal;
  std::cout << std:: endl;
  for(int i = 0; i < key.size(); ++i){
    hashVal += key[i];
    std::cout << "Hash Val for " << key[i] << " is: " << hashVal << std::endl;
  } 
 return hashVal % tableSize;
}

int hash2(std::string key, int tableSize){ 
  unsigned long hashVal;
  std::cout << std::endl;
  for(int i = 0; i < key.size(); ++i){
    hashVal = 37 * hashVal + key[i];  //key[0] + 37 * key[1] + 37 * 37 * key[2]
    std::cout << "Hash Val for " << key[i] << " is: " << hashVal << std::endl;    
  }
  return hashVal % tableSize;
}

void initTbl(std::string tbl[], int tableSize){
  for(int i = 0; i < tableSize; ++i){
    tbl[i] = "!";
  }
}


void dispTbl(std::string tbl[], int tableSize){
  std::cout << "The table is: ";
  for(int i = 0; i < tableSize; ++i){
    std::cout << tbl[i] << ",  ";
  } 
  std::cout << std::endl;
 }
//this added but not used yet
 int linearProbing(string hshArr[], const int tableSize, int bucket){
   for(int i = bucket + 1; i < tableSize; i++){
     if (hshArr[i] == "!"){
       return i;
     }
     if (i == (tableSize - 1)){
       for(int i = bucket - 1; i >= 0 ; i--){
         if (hshArr[i] == "!"){
          return i;
        }
      }
    } 
  } return -1;
 }

int main() {
  const int SIZE = 29;
  unsigned int bucket;
  std::string fauna[15] = {"ant", "antelope", "bat", "buffalo", "cat", "cow", "dog", "deer", "duck", "elephant", "eagle", "fox", "goat", "gazelle", "horse" };
  bool collision = 0;
  std::string hshTbl[SIZE];
  initTbl(hshTbl, SIZE);
  //std::cout << "Showing initial table: " << std::endl;
  dispTbl(hshTbl, SIZE);

  for(size_t i = 0; i < 15; ++i){
    collision = 0;
    bucket =  hash2(fauna[i], SIZE);
    std::cout << "It is bucket: " << bucket << std::endl;
    
    if(hshTbl[bucket] != "!"){
      collision = 1;
      std::cout << "There was a collision for " << fauna[i] << "\n" << std::endl;
      //if there is collision, modify this code to call a linearProbing function that
      //returns the next available bucket
    }
    if(!collision){
      hshTbl[bucket] = fauna[i];    
      std::cout << fauna[i] << " successfully stored in bucket " << bucket << "\n" << std::endl;
    }
    if(collision){
      hshTbl[linearProbing(hshTbl, 15, bucket)] = fauna[i];
      std::cout << fauna[i] << " successfully stored in bucket " << bucket << "\n" << std::endl;
    }
  }
 
  /*bucket = hash2("cat", SIZE);
  std::cout << "The bucket for cat by hash2: "<< bucket << std::endl;
  //add code for checking on collisions. Perform an insert only if NO COLLISION
  //if collision, call a separate function for linear probing 
  //(Pass it on the bucket value received from the hash function)
  hshTbl[bucket] = "cat";
  std::cout << "Showing table after inserting the key: " << std::endl;
  dispTbl(hshTbl, SIZE);*/
  dispTbl(hshTbl, SIZE);
  return 0;
}
