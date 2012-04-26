#ifndef __PROJECT__LPP__SAT_JAN_14_13_20_11_2006__FILE__LAPACKWORKSPACE_HH__INCLUDED
#define __PROJECT__LPP__SAT_JAN_14_13_20_11_2006__FILE__LAPACKWORKSPACE_HH__INCLUDED

#include <complex>
#include <vector>
#include <iostream>

namespace lpp
{

/**
 *  This struct and its specialization are made to cast result returned by
 *  LAPACK with the wrong type
 */

  template < class T > struct base{
    typedef T type_t; 
    typedef T base_t;
    static long int Getval(const type_t & v){
      return (long int)(v); 
    }
  }; 
    
  template <class T > struct base <std::complex<T> > {
    typedef std::complex < T > type_t; 
    typedef T base_t;
    static long int Getval(const type_t & v){
      return (long int)(v.real()); 
    }
  }; 
  
/**
 *  This class allows to use easily LAPACK workspace features
 */

  template < class T > class workspace{
  public :
    typedef typename base < T >::type_t   type_t;
    typedef typename base < T >::base_t   base_t;
    typedef std::vector < type_t > m_t;
    typedef std::vector < base_t > mb_t;
    typedef std::vector < long int > mi_t;
    /**
     * Sized constructor.
     * It allows to provide workspace memory from the beginning 
     */
   workspace(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz = 0):
     w(std::max(wsiz, size_t(1))), 
     rw(std::max(rwsiz, size_t(1))), 
     iw(std::max(iwsiz, size_t(1))),
     bw(std::max(bwsiz, size_t(1))),
     mquery(-1)
    {}
    /**
     * Trivial constructor.
     * Only the main work area get a necessary small provision.
     * The other will be allocated on demand.
     */
    workspace():w(1), rw(1), iw(1), bw(1), mquery(-1){ }
    ~workspace(){}
    //! to resize the main work area
    void resizew (size_t size){ w.reserve(size); } 
    //! to resize the real work area
    void resizerw(size_t size){rw.reserve(size); }    
    //! to resize the integer work area 
    void resizeiw(size_t size){iw.reserve(size); }  
    //! to resize the logical work area 
    void resizebw(size_t size){bw.reserve(size); }  

    bool isok(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz)const{ //! is the workspace sufficiently large
      return (wsiz >= w.size()) && (rwsiz >= rw.size())
        && (iwsiz >= iw.size()) && (bwsiz >= bw.size()); 
    }
    void realloc(size_t wsiz, size_t rwsiz, size_t iwsiz, size_t bwsiz = 0){
      if(wsiz >   w.size())  w.reserve(wsiz);
      if(rwsiz > rw.size()) rw.reserve(rwsiz);
      if(iwsiz > iw.size()) iw.reserve(iwsiz);
      if(bwsiz > bw.size()) bw.reserve(bwsiz);
    }
    type_t   * getw(){return &w[0]; }
    base_t   * getrw(){return &rw[0]; }
    long int * getiw(){return &iw[0]; }
    long int * getbw(){return &bw[0]; }
    const long int & neededsize(long int siz = 0){
      return (mldw =  siz ? siz : (base < type_t > ::Getval(w[0])));
    }
    const long int & neededisize(long int siz = 0){
      return mldiw = siz ? siz : iw[0];
    }
    const long int & neededrsize(long int siz = 0){
      return mldrw = siz ? siz : (long int)rw[0];
    }
    const long int & neededbsize(long int siz = 0){
      return mldbw = siz ? siz : bw[0];
    }
    const long int * query()const{return &mquery; } 
    void showstate(char unit =  'B')const{
      size_t total = w.size()*sizeof(T)+rw.size()*sizeof(base_t)+iw.size()*sizeof(long int);
      size_t ext = w.capacity()*sizeof(T)+rw.capacity()*sizeof(base_t)+
        iw.capacity()*sizeof(long int)+bw.capacity()*sizeof(long int);
      std::cout << "workspace is using a total amount of: ";
      std::cout << total/factor(unit) << " " << name(unit) << std::endl;
      std::cout <<  w.size() << " in w,  " << std::endl;
      std::cout << rw.size() << " in rw, " << std::endl;
      std::cout << iw.size() << " in iw, " << std::endl;
      std::cout << bw.size() << " in bw, " << std::endl;
      std::cout << "Total capacity workspace up to now is  : ";
      std::cout << ext/factor(unit) << " " << name(unit) << std::endl; 
      std::cout <<  w.capacity() << " in w,  " << std::endl;
      std::cout << rw.capacity() << " in rw, " << std::endl;
      std::cout << iw.capacity() << " in iw, " << std::endl;
      std::cout << bw.capacity() << " in bw, " << std::endl;
    }
  private :
    m_t w;
    mb_t rw;
    mi_t iw;
    mi_t bw;
    long int mldw, mldiw, mldrw, mldbw;
    const long int mquery;
    static inline size_t factor(char unit)
    {
      switch (unit){
      case 'M' :
      case 'm' :
        return(1024*1024); 
        break; 
      case 'B' :
      case 'b' :
      case 'O' :
      case 'o' :
        return 1;
        break; 
      case 'K' :
      case 'k' :
      default :
        return 1024; 
      }
      return 1024; 
    }
    static inline std::string name(char unit)
    {
      switch (unit){
      case 'M' :
      case 'm' :
        return("Megabytes"); 
        break; 
      case 'B' :
      case 'b' :
      case 'O' :
      case 'o' :
        return("Bytes"); 
        break; 
      case 'K' :
      case 'k' :
      default :
        return("Kilobytes"); 
      }
      return("Kilobytes"); 
    }
  };
  
}

#endif
