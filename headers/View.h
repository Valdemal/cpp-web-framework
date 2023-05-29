#ifndef CN8_VIEW_H
#define CN8_VIEW_H

#include <memory>
#include "Response.h"

namespace vovanex {
    class View {
    public:
        virtual std::shared_ptr<Response> get() const;
        virtual std::shared_ptr<Response> post() const;
        virtual std::shared_ptr<Response> put() const;
        virtual std::shared_ptr<Response> patch() const;
        virtual std::shared_ptr<Response> del() const;
        virtual std::shared_ptr<Response> head() const;
        virtual std::shared_ptr<Response> options() const;
        virtual std::shared_ptr<Response> method_not_allowed() const;
    };
};


#endif //CN8_VIEW_H
