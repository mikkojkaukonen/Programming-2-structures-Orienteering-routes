# Programming-2-structures-Orienteering-routes
Tampere University, Projects made in the course Programming 2: structures

Data processed by the program

The input file given to the program contains lines, each of which has a variant number of data fields, separated by semicolons. The structure of an input file accepted by the program can, for example, be as follows:

15;10

Tree;1;1;200;T

Landing;4;7;700;L

Stump;7;8;700;S

Rock;2;3;500;R

Boulder;5;5;650;B

Pond;4;1;340;P

Distant hut;13;9;800;D

ROUTES

Shorter;Tree;Rock;Boulder

Longer;Rock;Distant hut;Pond;Tree

Longest;Rock;Landing;Stump;Distant hut;Pond;Tree

The first line tells the size of the map (coordinate system): width and height as (positive) integers.

The next lines, after the first one, enumerate some number of control points. The list ends at the line that consists only of the word ROUTES. Each line describing a control point gives the name of the point, its x- and y-coordinates, the height of the terrain at the point in meters, and the marker of the point (a single character).

After the line ROUTES, the file enumerates the routes, each of them in a line of its own. Each line describing a route gives the name of the route and the names of those control points that belong to the route. A route can have any (finite) number of control points. A route can have only such points that have been introduced at the beginning part of the input file. The routes are unidirectional.

The names of both control points and routes may consist of several words.

Reading the input file

When the program starts up, it reads the name of the input file from the user. For example:

Input> points.input

If it cannot open the input file in a readable mode, the program will print the text:

Error: Can't read file

After that, the program terminates with no other prints with the return value EXIT_FAILURE.

If the input file can be opened but the file does not correspond to the definition, the program prints the error message:

Error: Incorrect line in input file

and terminates with the return value EXIT_FAILURE. This can be the case, if, for example, the first line of the input file contains something else than two integers separated by semicolons.

From each control point line, the program checks that the line consists of five data fields, the second, third, and fourth of which are integers. In addition, it checks that the marker, i.e. the fifth data field consists of a single character. If any of these conditions do not hold, the aforementioned error message will be printed and the program terminates.

For each route, the input file must have at least a name and the names of the first and last control points. In other words, each route has at least three data fields. If this does not hold, the aforementioned error message will be printed and the program terminates.

Besides the first and last control points, there can be other points as well that belong to the route. If the input file gives such a point for a route that has not been introduced, i.e. that cannot be found from the beginning part of the file, the program prints the error message:

Error: Points specified in route can't be found

and terminates with the return value EXIT_FAILURE. You can assume that the control points in a route are not circular, i.e. each point can be in a route only once.

The program parses the lines of the input file and stores the information in an adequate internal data structure. Although a single control point may belong to several routes, you must not store the point into memory more than once. However, the name of the point can be stored more than once.

To make the task easier

The code given in the template already checks the correct format of the input file. The same holds true for checking the right amount of parameters and other parsing actions of the user-given commands.

Commands and error messages in general

After reading the input file, the program starts the actual execution. Each time the user is expected to give input, the program prints the prompt:

CMD>

To this prompt, the user can give the commands listed a bit later.

If the user gives another command, not listed below, the program prints the error message:

CMD> mmm

Error: Unknown command

CMD>

After completing the execution of a command given by the user, the program prints the prompt again, until the user gives the command QUIT.

Reading the commands has been implemented in the template code in Cli class by using function pointers.

Mandatory commands with their error messages

All the commands listed in this section must be implemented and they must work to get any points from the project. If you implement only the commands in this section, the scale 0-30 will be used in evaluating your project.

QUIT - The program terminates with the return value EXIT_SUCCESS without printing anything.

MAP - The command prints the map. Assumimg that the content of the input file is that shown earlier at ”Data processed by the program”, the map looks like:

CMD> MAP

   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15

 1  T  .  .  P  .  .  .  .  .  .  .  .  .  .  .

 2  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

 3  .  R  .  .  .  .  .  .  .  .  .  .  .  .  .

 4  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

 5  .  .  .  .  B  .  .  .  .  .  .  .  .  .  .

 6  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

 7  .  .  .  L  .  .  .  .  .  .  .  .  .  .  .

 8  .  .  .  .  .  .  S  .  .  .  .  .  .  .  .

 9  .  .  .  .  .  .  .  .  .  .  .  .  D  .  .

10  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

CMD>

ROUTES - The command prints the routes preceded by a dash, line by line. The routes will be printed in alphabetical order. For example:

CMD> ROUTES

Routes:

 - Longer

 - Longest

 - Shorter

CMD>

ROUTE <route> - The command prints the control points belonging to the given route. Each control point will be printed in the line of its own. The points will be separated by an arrow and printed in the order of the route, i.e. in the same order as they were given in the input file. For example:

CMD> ROUTE Shorter

Tree

 -> Rock

 -> Boulder

CMD>

The command must have exactly one parameter. If this is not the case, the program gives the error message:

CMD> ROUTE

Error: Wrong amount of parameters

CMD>

If the given route is unknown, the program prints the error message:

CMD> ROUTE unknown

Error: Route named unknown can't be found

CMD>

POINTS - The command prints the controls points given in the input file with their markers. The printing order is the alphabetical order according to the point names. For example:

CMD> POINTS

Points:

 - Boulder : B

 - Distant hut : D

 - Landing : L

 - Pond : P

 - Rock : R

 - Stump : S

 - Tree : T

CMD>

Voluntary commands with their error messages

If you, besides the mandatory commands, implement also the commands introduced in the section, the scale 0-50 will be used in evaluating your project.

LENGTH <route> - The command prints the length of the given route. The length is calculated as the sum of distances between each subsequent points. The automatic testing system expects the result to be given as a number consisting of two digits. For example:

CMD> LENGTH Shorter

Route Shorter length was 5.8

CMD>

Also this command must have exactly one parameter. If this is not the case, the program gives the same error message as with ROUTE command in the corresponding situation. Similarly, in the case of an unknown route as a parameter, the error message is the same as with ROUTE command.

RISE <point> - The command prints the greatest continuous rise, when proceeding from the given control point along to some route. Continuous rise means a partial route, the starting point of which is the given point and which contains no declivity, just only rise or flat. Therefore searching for such a partial route can be stopped, when the route starts to go down, even if it will later go even higher. For example:

CMD> RISE Rock

Greatest rise after point Rock, 300 meters, is on route(s):

 - Longer

 - Longest

CMD>

The height of the point Rock is 500 meters and that of the point Distant hut is 800 meters. The difference between these heights is the greatest rise. Namely, there is a route from Rock to another point Boulder (the height of which is 650), but the rise between these points is smaller. The same difference in heights, 300 meters can be found also in the route Longest, when going through the control points Landing and Stump. Either this route has no declivity, flat parts between rises are allowed.

The rise is calculated from the longest possible route. For example:

CMD> RISE Tree

Greatest rise after point Tree, 450 meters, is on route(s):

 - Shorter

CMD>

The above rise can be found, when going the whole route Shorter, i.e. starting from Tree, passing Rock, and finally reaching Boulder. Namely, the heights of these points are 200, 500, and 650 meters.

The following figure clarifies the case. It takes only heights into account, not distances between control points. The route Shorter is depicted with blue and its starting point with a blue circle. Correspondingly, the route Longer is depicted with red and its starting point with a red circle. Finally, the route Longest is depicted with darker red, and it has the same starting point as Longer.

It is possible that the rest of the route starting from the given point does not raise at all.

CMD> RISE Pond

No route rises after point Pond

CMD>

There is a route from Pond to Tree, but the height of Tree is smaller than that of Pond.

The command requires exactly one parameter. If this is not the case, the given error message is the same as with the command ROUTE in the corresponding situation.

If the given point is unknown, the program prints the error message:

CMD> RISE unknown

Error: Point named unknown can't be found

CMD>

Modules of the program

The code template consists of four modules that will be introduced below. In addition to them, you must add at least one new class.

The main program module is very simple. It just reads the name of the input file and and starts the command interpreter that goes on until the QUIT command is given by the user. There is no need to change the main program.

The command line interpreter, i.e. the class Cli has been defined and implemented in files cli.hh and cli.cpp. It identifies the commands from the user input. This module is completely implemented in the code template, and you need not modify it. It is not necessary to understand its functionality. However, since the topic of the round is modularity, this is a good example to be explored as a whole.

The program has also the module Parser that is not a class. Its purpose is to parse the data found in the input file and check the validity of the data. The module has only a single public function read_input_from_file that is declared in the file parser.hh. From the file parser.cpp, you can find the implementation of the aforementioned function as well as implementations of private functions.

The file orienteeringmap.hh, i.e. the header file of the class OrienteeringMap can be found in the code template. However, you can (and you should) modify it as you wish.

Your task is to implement the methods in the file orienteeringmap.cpp. The public methods of the class are introduced below:

set_map_size - sets the width and height for the map.

add_point - adds a control point into the map. Adding succeeds if the coordinates of the points are inside the map and if the point has not been previously added.

connect_route - connects the given two points as the part of the given route (the two points will be subsequent points in the route). Connecting succeeds if the points can be found in the map.

print_map - prints the map, i.e. implements the MAP command.

print_routes - prints the names of the routes, i.e. implements the ROUTES command.

print_points - prints the control points, i.e. implements the POINTS command.

print_route - prints the route, i.e. implements the ROUTE command.

route_length - counts the length of the route, i.e. implements the LENGTH command.

greatest_rise - counts the greatest rise, i.e. implements the RISE command.

Besides the public methods above, you can add private methods for the class as you wish.


In addition to completing the class OrienteeringMap, you must add a new class. Natural candidate classes to be added are Point and Route. It is enough to add one of them, but you can add also both. On the other hand, after adding one, you perhaps realize that there is no need for the other one. Which one to select to be added (first) depends on whether you think that routes consist of control points, or that control points belong to routes.

When implementing the program, think carefully which parts suit better in class OrienteeringMap and which ones in the new class. Note that implementing an action can require adding methods having same names in both of these classes such that the method in one class implements its portion of the action.

An action (e.g. printing method) should be placed in the class, the data of which is processed (printed). For example, a printing chain can start from a ”bigger” class (OrienteeringMap), which prints something by itself and then asks its parts to print their portion. Here a bigger class means a class, which has intances of other classes as its parts (attributes).

While designing and implementing the assignment, it is especially important to pay attention to how instances (objects or pointers to them) of one class can be attributes of another class.
