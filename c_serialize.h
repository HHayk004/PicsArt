struct VTableSerialize {
    public:
	    char* serialize();
	    void deserialize(const char* str);
};

struct Serializable {
    public:
        VTableSerialize* vptr;	
};

struct VTablePerson {
    public:
		Person(char* name, int age);
		~Person();
	
		void displayInfo();
		char* serialize();
		void deserialize(const char* str);
}

struct Person {
	private:
        Serializeable parent;
		char* name;
		int age;

    public:
        VTablePerson* vptr;
};

struct Any {
	public:
		~Any();

		void set_value(const char* str);
		char* get_value();
};

class Integer {
	private:
		int m_value;
        Any parent;

	public:
		Integer();
		
		void set_value(const char* str);
		char* get_value();
};

class Float {
	private:
		float m_value;
        Any parent;

	public:
		Float();
		void set_value(const char* str);
	    char* get_value();
};

class Boolean : public Any {
	private:
		bool m_value;
	    Any parent;

	public:
		Boolean();
		void set_value(const char* str);
		char* get_value();
};

