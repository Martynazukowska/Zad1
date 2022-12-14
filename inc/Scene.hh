#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>

#include "Configuration.hh"
#include "MobileObj.hh"

/*!
 * \file
 * \brief Definition of PluginManager
 *
 *  File contains definition of PluginManager
 */
    /*!
    * \brief Class used to represent a manager for plugins
    *
    *  Class used to represent a manager for plugins. Contains all the instances and library interfaces
    */
    class Scene 
    {
        private:
            /*!
            * \brief Map of all mobile objects
            *
            *  Map of all mobile objects
            */
            std::map<std::string, std::shared_ptr<MobileObj>> mapMobileObjects;
        public:
            /*!
            * \brief Add mobile object to the scene
            * \param[in] handler - pointer to mobile object to be added to scene
            * 
            */
           Scene();
           ~Scene();
            void AddMobileObject(Configuration *pConfig);

            std::map<std::string, std::shared_ptr<MobileObj>> & GetMapMobileObjects() {return mapMobileObjects;}
            std::shared_ptr<MobileObj> TakeMobileObj(const char *ObjName)
            {
                return mapMobileObjects[ObjName];
            }
            std::shared_ptr<MobileObj> TakeMobileObj(const std::string &ObjName)
            {
                return mapMobileObjects[ObjName];
            }
            std::shared_ptr<MobileObj> operator [] (std::string &Name)
            {
                return mapMobileObjects[Name];
            }
            std::shared_ptr<MobileObj> operator [] (char *Name)
            {
                return mapMobileObjects[Name];
            }

    };


#endif