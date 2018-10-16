/* serialization.h
 * Contains class to serialize/deserialize program data
 */

// Serializes program data. Serialized data is not generic
// as program objects are defined
class Serializer
{
  public:
    static Serializer& Instance()
    {
      static Serializer instance;
      return instance;
    }
    Serializer(Serializer const&)     = delete;
    void operator=(Serializer const&) = delete;
  private:
    Serializer() {}
};
