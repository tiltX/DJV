// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020 Darby Johnston
// All rights reserved.

#pragma once

#include <djvTestLib/Test.h>

namespace djv
{
    namespace SystemTest
    {
        class EventFuncTest : public Test::ITest
        {
        public:
            EventFuncTest(
                const System::File::Path& tempPath,
                const std::shared_ptr<System::Context>&);
            
            void run() override;

        private:
            void _enum();
            void _serialize();
        };
        
    } // namespace SystemTest
} // namespace djv

