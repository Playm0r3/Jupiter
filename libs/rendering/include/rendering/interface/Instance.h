//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_INSTANCE_H
#define JUPITER_INSTANCE_H

namespace jupiter::rendering {

    class Instance {

    public:

        Instance() = default;
        virtual ~Instance() = default;

        virtual void createInstance() = 0;
        virtual void destroyInstance() = 0;

    };

}


#endif //JUPITER_INSTANCE_H