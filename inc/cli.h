class CommandLineInterface {
    public:
        CommandLineInterface(int argc, char** argv);
        ~CommandLineInterface();
        void execute();

        // setters
        void argc(int a);
        void argv(char** argv);
    private:
        int _argc;
        char** _argv;
};