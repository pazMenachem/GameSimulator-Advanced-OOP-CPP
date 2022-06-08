
#ifndef GAMESIMULATOR_TROOPER_H
#define GAMESIMULATOR_TROOPER_H

#include <memory>
#include "Vehicle.h"

#include "map"


class Trooper: public Vehicle{
    using warehousePtr = shared_ptr<Warehouse> ;

private:

    map<warehousePtr,bool> _visitedMap;
    warehousePtr firstVisit;
    warehousePtr nextDest;

public:

    Trooper(string &name,const Point& location, string Type): Vehicle(name,location, Type){Vehicle::setState("Stopped");};
    ~Trooper() {};
    void getStatus();
    void setMapRouts(vector<warehousePtr> &warehouses);
    void init(vector<warehousePtr> &wHouseLst, shared_ptr<Warehouse> first);
    warehousePtr getNextDest();

    double getDistance(const warehousePtr& dest);
};

#endif //GAMESIMULATOR_TROOPER_H
