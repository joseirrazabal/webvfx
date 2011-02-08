// Copyright (c) 2010 Hewlett-Packard Development Company, L.P. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MLTWEBVFX_EFFECTS_MANAGER_H_
#define MLTWEBVFX_EFFECTS_MANAGER_H_

extern "C" {
    #include <mlt/framework/mlt_service.h>
}

namespace WebVFX
{
    class WebEffects;
}

namespace MLTWebVFX
{
class ServiceLock;

class ServiceManager
{
public:
    WebVFX::WebEffects* getWebEffects();

    static const char* kURLPropertyName;

private:
    friend class ServiceLock;
    ServiceManager(mlt_service service);
    ~ServiceManager();
    bool initialize(int width, int height);

    mlt_service service;
    WebVFX::WebEffects* webEffects;
};

}

#endif
