/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS04_CONFIRMATION_SENDER_H
#define WS04_CONFIRMATION_SENDER_H

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        Reservation **_reservations;
        size_t _size;

    public:
        ConfirmationSender();

        ConfirmationSender &operator+=(const Reservation &reservation);

        ConfirmationSender &operator-=(const Reservation &reservation);

        ConfirmationSender(const ConfirmationSender &confirmationSender);

        ConfirmationSender &operator=(const ConfirmationSender &confirmationSender);

        ConfirmationSender(ConfirmationSender &&confirmationSender);

        ~ConfirmationSender();

        ConfirmationSender &operator=(ConfirmationSender &&confirmationSender);

        friend std::ostream &operator<<(std::ostream &os, const ConfirmationSender &confirmationSender);

    private:
        void setEmpty();
    };
}


#endif
