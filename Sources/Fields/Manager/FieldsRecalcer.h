#pragma once

namespace automat {

    class AbstractField;
    class SimpleSquareTestField;

    class FieldsRecalcer
    {
    public:
        FieldsRecalcer() = default;

    private:
        void recalc(SimpleSquareTestField* pField);

    public:
        void recalcField(AbstractField* pField);

    };

}



