class World{
public:
	int x;
	int y;

	World();
	~World();


	void CreateWorld(int * &room)const;

	void DestroyWorld(int * &room);
};
	
	
	
	 
	

struct Room{

	char name[10];
	char description[];

};

struct Player{

	char position[10];

};

struct Exits{
	char origin[10];
	char destination[10];
	char description[];
	bool door();

};