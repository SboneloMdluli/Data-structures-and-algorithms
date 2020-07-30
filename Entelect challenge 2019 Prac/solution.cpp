#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;


vector<vector<char>> grid ={{'#','c','#','#','#','#','#','#','b','#'},
				{'#','#','#','#','#','#','#','#','#','#'},
				{'#','#','#','#','#','#','#','A','#','D'},
				{'#','#','#','#','g','#','#','#','#','#'},
				{'B','#','#','#','#','#','#','#','#','#'},
				{'#','#','F','#','#','#','#','#','#','#'},
				{'C','#','G','#','d','#','#','#','#','#'},
				{'#','#','#','#','#','#','#','f','#','#'},
				{'#','#','#','#','#','#','#','#','#','a'},
				{'#','E','#','#','#','e','#','#','#','#'}};

struct worm 
{ 
   vector<pair<char,char>> cratenana_pair;
   int distso_far = 0;
   pair<int,int> pos;
};  

int const xmax = grid.size()-1;

int crate_number = 0;

int worm_number = 4;

priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> cratesFromOrig;

unordered_map<char,vector<pair<int,int>>> lookup;

unordered_map<char,pair<int,int>> bases;

unordered_map<char,pair<int,int>> crates;

vector<worm> worm_group;

void makeDist(){

	// easy calculation of distances between crate and banana
	for(int i=0; i<grid.size();i++){
	
	   for(int j=0; j<grid[i].size();j++){
	    
	    if(isalpha(grid[i][j])){  
	        
	        //base positions
	        if(islower(grid[i][j])){
	            char base = grid[i][j];
	            bases[base] = make_pair(xmax-i,j);
	        }
	        
	        
    	   	if(isupper(grid[i][j])){
    	   	    
    	   	    char crateID = grid[i][j];
                   // for getting nearest crate from origin used to introduce new worm to the map 
    	   	   cratesFromOrig.emplace((xmax-i)+j,grid[i][j]);
    	   	   
    	   	     // crate position
    	   	    crates[crateID] = make_pair(xmax-i,j);
    	   	    crate_number++;
    	   	}
	   
	        // for banana-crate distance fast calculation
	        char curr = tolower(grid[i][j]);
	        lookup[curr].emplace_back(xmax-i,j);
	   	
	    }

	   }

	}
	
	
	for(auto coord : lookup){
	    
	    auto points =  coord.second;
	    // points = vector of coordinates for each char
	    // (x1-x2) + (y1-y2) between banana and crate
	    
	    auto dist = abs(points[0].first -points[1].first) + abs(points[0].second -points[1].second);
	    
	    lookup[coord.first].emplace_back(0,dist); // mark as unvisited using 0
	        
	}

}


void introduce_worm(){
    
        if(!cratesFromOrig.empty() && worm_number ){
            struct worm wormx;

            char starting_crate = tolower(cratesFromOrig.top().second);
            
            if(lookup[starting_crate].back().first ==0 ){
                
                wormx.cratenana_pair.emplace_back(toupper(starting_crate),starting_crate);
                
                wormx.distso_far = cratesFromOrig.top().first + lookup[starting_crate].back().second;
                lookup[starting_crate].back().first = 1; // mark as visited
                
                wormx.pos = bases[starting_crate];
                
                worm_group.emplace_back(wormx);
                crate_number--;
                worm_number --;
            }
              cratesFromOrig.pop();
        }
    
}


struct comparator
{
    inline bool operator() (const worm& worm1, const worm& worm2)
    {
        return (worm1.distso_far < worm2.distso_far);
    }
};


void work(){
   
   introduce_worm();
  
    
    while(crate_number){
            
        sort(worm_group.begin(),worm_group.end(),comparator());
        
        int min_to_beat = worm_group[0].distso_far;
        
     
        if(!cratesFromOrig.empty() && worm_number){
        
            min_to_beat = min(cratesFromOrig.top().first,min_to_beat);
        }
        
       
        if(min_to_beat == worm_group[0].distso_far){
            
            vector<pair<int,char>> curr_options;
            int activemin_dist = INT_MAX;
            char minCrate = ' ';
            
            // look for nearest crate
            for(auto crate_banana_pair : lookup){
              
                if(crate_banana_pair.second.back().first == 0){ // if unvisted pair
                    
                    
                    char crateID = toupper(crate_banana_pair.first);
                    
                    auto dist = abs(worm_group[0].pos.second - crates[crateID].second) + abs(worm_group[0].pos.first - crates[crateID].first) + worm_group[0].distso_far;
                    
                    
                    if(dist < activemin_dist){
                        
                        activemin_dist = dist;
                        minCrate  = crateID;
                    }
                       
                }
            }
            
            worm_group[0].cratenana_pair.emplace_back(minCrate,tolower(minCrate));
            
            worm_group[0].distso_far = activemin_dist; // move to crate
         
            worm_group[0].distso_far += lookup[tolower(minCrate)].back().second; // move from crate to base
            
            worm_group[0].pos = bases[tolower(minCrate)]; // update position
            
            lookup[tolower(minCrate)].back().first = 1; // mark as visited
            
            crate_number--;
            
        }else{
            introduce_worm();
        }
        
    }
}


int main()
{
	    
    makeDist();
    
    work();
    
    for(auto worm_list : worm_group){
        
        string s;
        
        for(auto visited: worm_list.cratenana_pair){
            
            s += visited.first;
            s += ',';
            s += visited.second;
            s +=',';
        }
        s.back() = ' ';
        cout << s <<endl;
 
    }

    return 0;
}

