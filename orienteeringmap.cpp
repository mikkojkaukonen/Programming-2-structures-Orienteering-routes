/*
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 *
 * Project3: Suunnistus / Orienteering
 *
 * Kuvaus:
 *
 * Ohjelma, joka käynnistyessään lukee suunnistusreitteihin liittyviä
 * tietoja tiedostosta, tallentaa ne sopivaan tietorakenteeseen ja
 * antaa käyttäjälle mahdollisuuden tehdä hakuja kyseiseen tietorakenteeseen.
 *   Ohjelmalle annetaan syötteenä tiedosto, jonka kullakin rivillä on
 * vaihteleva määrä tietokenttiä puolipisteellä eroteltuna toisistaan.
 * Ensimmäisellä rivillä kerrotaan kartan (koordinaatiston) koko: leveys ja
 * korkeus (positiivisina) kokonaislukuina. Sen jälkeisillä riveillä luetellaan
 * haluttu määrä rasteja. Luettelo loppuu riviin, jolla lukee pelkästään sana
 * ROUTES. Rasteista kerrotaan rastin nimi, sen x- ja y-koordinaatit, maaston
 * korkeus kyseisen rastin kohdalla metreinä sekä rastin tunnus.
 * Rivin ROUTES jälkeen tiedostossa luetellaan reitit,
 * kukin omalla rivillään. Kustakin reitistä kerrotaan nimi sekä niiden
 * rastien nimet, joita pitkin reitti kulkee. Reitillä voi olla rasteja mikä
 * tahansa (äärellinen) määrä. Reitillä voi olla vain sellaisia rasteja,
 * jotka on esitelty tiedoston alkuosassa. Reitit ovat yksisuuntaisia.
 * Sekä rastien että reittien nimissä voi olla useita sanoja.
 *
 *   Ohjelmassa toteutettavat komennot:
 *
 *   QUIT - Ohjelman suoritus päätty paluuarvoon EXIT_SUCCESS
 *   ilman, että ohjelma tulostaa mitään.
 *   MAP - Komento tulostaa kartan.
 *   ROUTES - Komento tulostaa aakkosjärjestyksessä ranskalaisilla
 *   viivoilla allekkain kaikki annetut reitit.
 *   ROUTE <reitti> - Komento tulostaa annetulle reitille kuuluvat rastit
 *   kunkin omalle rivilleen nuolella erotetulta. Rastit tulostetaan reitin
 *   mukaisessa järjestyksessä, eli samassa järjestyksessä kuin ne esiintyivät
 *   syötetiedostossa.
 *   POINTS - Komento tulostaa syötetiedostossa annetut rastit ja niiden
 *   tunnukset rastien nimien mukaisessa aakkosjärjestyksessä.
 *   LENGTH <reitti> - Komento tulostaa annetun reitin pituuden. Tämä lasketaan
 *   reitille kuuluvien peräkkäisten rastien välisten etäisyyksien summana.
 *   RISE <rasti> - Komento tulostaa suurimman jatkuvan nousun, joka voi löytyä,
 *   kun annetulta rastilta lähdetään etenemään jotakin reittiä pitkin.
 *   Jatkuva nousu tarkoittaa sellaista osareittiä, jonka alkupisteenä on annettu
 *   rasti ja jonka varrella ei ole lainkaan laskua, vaan pelkkää nousua tai
 *   tasamaata.
 *
 *
 *  Description:
 *
 * A program that, upon startup, reads navigation route-related
 * information from a file, stores it in a suitable data structure, and
 * allows the user to make queries to this data structure.
 *   The program is given a file as input, where each line contains
 * a variable number of fields separated by semicolons.
 * The first line specifies the size of the map (coordinate system): width and
 * height (both positive) as integers. The subsequent lines list
 * the desired number of control points. The list ends with a line containing
 * only the word ROUTES. For each control point, the name of the control point,
 * its x- and y-coordinates, the terrain height at that control point in meters,
 * and the identifier of the control point are provided.
 * After the line containing ROUTES, the file lists the routes,
 * each on its own line. For each route, its name and the names of
 * the control points through which the route passes are listed. A route can have
 * any (finite) number of control points. A route can only contain control points
 * that have been presented in the beginning of the file. Routes are unidirectional.
 * Both control point names and route names can consist of multiple words.
 *
 *   Commands implemented in the program:
 *
 *   QUIT - The program terminates with a return value of EXIT_SUCCESS
 *   without printing anything.
 *   MAP - Command prints the map.
 *   ROUTES - Command prints all given routes in alphabetical order,
 *   each on its own line.
 *   ROUTE <route> - Command prints the control points belonging to the given route
 *   on separate lines with arrows between them. Control points are printed in the
 *   order they appear in the input file.
 *   POINTS - Command prints the control points and their identifiers
 *   in alphabetical order according to the control point names.
 *   LENGTH <route> - Command prints the length of the given route. This is calculated
 *   as the sum of distances between consecutive control points on the route.
 *   RISE <control point> - Command prints the greatest continuous ascent that can be found
 *   when progressing along any route starting from the given control point.
 *   Continuous ascent refers to a sub-route starting at the given control point
 *   where there is no descent, only ascent or flat terrain.
 *
 *
 * Writer: Mikko Kaukonen
 * */



#include "orienteeringmap.hh"

OrienteeringMap::OrienteeringMap()
{

}

// Releases the reserved memory
OrienteeringMap::~OrienteeringMap()
{
    {
        for(map<string, point*>::iterator itr = pointsdata_.begin();
            itr != pointsdata_.end(); itr++)
        {
            delete (itr->second);
        }
        pointsdata_.clear();
    }

    {
        for(map<string, route*>::iterator itr = routesdata_.begin();
            itr != routesdata_.end(); itr++)
        {
            delete (itr->second);
        }
        routesdata_.clear();
    }


}

void OrienteeringMap::set_map_size(int width, int height)
{

    this->x_ = width;
    this->y_ = height;

    // Defins height of the orienteermap
    for( int y = 0; y < height; ++y )
    {
        vector< point* > row;

        // Defins widht of the orienteermap
        for( int x = 0; x < width; ++x )
        {
            point* data = nullptr;
            row.push_back(data);
        }

        // Creates the orinteermap
        orienteermap_.push_back( row );
    }

}

void OrienteeringMap::add_point
(string name, int x, int y, int height, char marker)
{

    // Checks if point exists in data structure
    if(pointsdata_.find(name) == pointsdata_.end())
    {

        // If the point does not allready exist adds information
        // of the point from class point to the orienteermap
        point* new_point = new point{name, x, y, height, marker};
        pointsdata_.insert({name, new_point});

        orienteermap_.at(y-1).at(x-1) = new_point;


    }

}

bool OrienteeringMap::connect_route
(string from, string to, string route_name)
{

    point* from_point = pointsdata_.at(from);

    point* to_point = pointsdata_.at(to);


    // Checks if points exists in data structure
    if(pointsdata_.find(from) == pointsdata_.end() ||
            pointsdata_.find(to) == pointsdata_.end())
    {
        // If the points does not exist returns false
        return false;
    }

    else
    {

        // Checks if the route allready exists
        if(routesdata_.find(route_name) == routesdata_.end())
        {
            // If the route does not exist, creates the route and  adds the
            // point to the route using add_route funktion at the class route
            route* one_route = new route;

            one_route->add_route(from_point, to_point);
            routesdata_.insert({route_name, one_route});
        }

        // If the route allready exists adds new points to the back
        // of the route using add_route funktion at the class route.
        else
        {
            routesdata_.at(route_name)->add_route(from_point, to_point);

        }
        return true;
    }

}

void OrienteeringMap::print_map() const
{
    int i = 0;
    int j = 0;

    cout << " ";

    // Adds the coordinating scale numbers to the edges of the orienteermap
    for(j = 0; j < x_; j++)
    {

        // These checks has been added to maintain scale ratios of the map
        // as 3 characters are to be reserved for each square.
        if(j < 9)
        {
            cout <<"  " << j +1;
        }
        else
        {
            cout << " " << j + 1;
        }
    }

    cout << endl;


    for(i = 0; i < y_; ++i)
    {
        if(i < 9)
        {
            cout <<" " << i +1;
        }
        else
        {
            cout << i + 1;
        }


    // Fills empty squares of the orienteermap
    for(j = 0; j < x_; ++j)
    {

        // If the squre is empty(nullptr) inserts . to the square
        if(orienteermap_.at(i).at(j) == nullptr)
        {
            cout << "  .";
        }
        else
        {
            // If there is a information of a point allready added to the
            // square, prints the points id.
            cout << "  " << orienteermap_.at(i).at(j)->marker();
        }
    }
        cout << endl;
    }
}


void OrienteeringMap::print_routes() const
{
    cout << "Routes:" << endl;

    for(auto & entry : routesdata_)
    {
        // Prints the routes in alphabetical order
        cout << " - " << entry.first<< endl;
    }
}


void OrienteeringMap::print_points() const
{
    cout << "Points:" << endl;

    for(auto & entry : pointsdata_)
    {

        // Prints the points to an alphabetic order.
        cout << " - " << entry.first<< " : " << entry.second->marker() << endl;

    }
}


void OrienteeringMap::print_route(const string &name) const
{

    // Cheks that the name of the given route exist
    if(routesdata_.find(name) == routesdata_.end())
     {
         cout << "Error: Route named " << name << " can't be found" << endl;
     }

     else
     {
        // Prints points of the route in the correct order,
        // using print_one_route function of the class route.
        routesdata_ .at(name)->print_one_route();

     }
}

void OrienteeringMap::route_length(const string &name) const
{

    // Cheks that the name of the given route exist
    if(routesdata_.find(name) == routesdata_.end())
     {
         cout << "Error: Route named " << name << " can't be found" << endl;
     }

    else
    {
        // Print the length of the route
        // using route_length funktion at route class
        cout << setprecision(2) << "Route " << name << " length was ";
        routesdata_.at(name)->route_length();
        cout << endl;


    }
}

void OrienteeringMap::greatest_rise(const string &point_name) const
{

    // Variable to store the greatest rise
    int greatest_rise = 0;

    // Vector to store the names of the routes,
    // wich have the greatest rise of a named point.
    vector<string> rise_routes;


    // Cheks that the name of the given point exist
    if(pointsdata_.find(point_name) == pointsdata_.end())
    {
        cout << "Error: Point named " << point_name
             << " can't be found" << endl;
    }

    else
    {
        for(auto & entry : routesdata_)

        {   
            // Retrieve the scores of the rises
            int route_rise = entry.second->greatest_rise(point_name);

            // Combines the values of the rises
            if(route_rise >= greatest_rise)
            {

                // If the new value is greater than the
                // last one sets new value to greatest_rise and
                // clears the vector of the routes for greatest rise
                if(route_rise > greatest_rise)
                {
                    greatest_rise = route_rise;

                    rise_routes.clear();
                }


            // Adds the names of the routes wich have greatest rise to vector.
            rise_routes.push_back(entry.first);



            }

        }

        // Prints the results of the calculations.
        if (greatest_rise <= 0)
        {
            cout << "No route rises after point " << point_name << endl;
        }

        else
        {
            cout <<"Greatest rise after point " << point_name << ", "
                 << greatest_rise  << " meters, is on route(s):" << endl;

            unsigned int i = 0;

            while (i < (rise_routes.size()))
            {
                 cout << " - " << rise_routes.at(i) << endl;

                 ++i;
            }

        }


    }

}

